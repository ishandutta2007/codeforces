import std.algorithm;
import std.conv : to;
import std.container;
import std.numeric : gcd;
import std.range;
import std.stdio;
import std.typecons : Tuple, tuple;

string readToken() {
    static string[] tokens;
    while (tokens.empty)
        tokens = readln.split;
    auto token = tokens.front;
    tokens.popFront;
    return token;
}

int readInt() {
    return readToken.to!int;
}

void work() {
    int n0 = readInt;
    int n1 = readInt;
    string[] grid = new string[n0];
    for (int i = 0; i < n0; ++i) {
        grid[i] = readToken;
    }

    bool isBanned(int x, int y) {
        int s = x + y;
        return s > 0 && s % 2 == 0;
    }

    int id(int x, int y) {
        return x * n1 + y;
    }

    int n = n0 * n1, m = 0, demands = 0;
    auto edges = new Tuple!(int, int)[(n0 - 1) * n1 + n0 * (n1 - 1)];

    void addEdges(int i, int j) {
        static const int[] DELTA_X = [-1, 0, 0, 1];
        static const int[] DELTA_Y = [0, -1, 1, 0];
        for (int k = 0; k < 4; ++k) {
            int ii = i + DELTA_X[k];
            int jj = j + DELTA_Y[k];
            if (0 <= ii && ii < n0 && 0 <= jj && jj < n1 && grid[ii][jj] == 'O') {
                edges[m++] = tuple(id(i, j), id(ii, jj));
            }
        }
    }

    for (int i = 0; i < n0; ++i) {
        for (int j = 0; j < n1; ++j) {
            if (grid[i][j] == 'O' && isBanned(i, j)) {
                demands += 2;
                addEdges(i, j);
            }
        }
    }

    int[] parent = new int[n], count = new int[n], dist = new int[m],
        prev = new int[m], queue = new int[m];
    bool[] inside = new bool[m + 2], ok1 = new bool[m], ok2 = new bool[m];

    int findRoot(int u) {
        return parent[u] == -1 ? u : (parent[u] = findRoot(parent[u]));
    }

    void merge(int a, int b) {
        parent[findRoot(a)] = findRoot(b);
    }

    void debugPlan(int[] prev, int u) {
        auto result = new char[][n0 * 2 - 1];
        for (int i = 0; i < n0 * 2 - 1; ++i) {
            result[i] = new char[n1 * 2 - 1];
            fill(result[i], ' ');
        }
        for (int i = 0; i < n0; ++i) {
            for (int j = 0; j < n1; ++j) {
                result[i * 2][j * 2] = isBanned(i, j) ? cast(char)('0' + count[id(i, j)]) : '?';
            }
        }
        for (int i = 0; i < m; ++i) {
            if (inside[i]) {
                int s = min(edges[i][0], edges[i][1]);
                int s1 = max(edges[i][0], edges[i][1]);
                if (s + 1 == s1) {
                    result[s / n1 * 2][s % n1 * 2 + 1] = '-';
                }
                else {
                    result[s / n1 * 2 + 1][s % n1 * 2] = '|';
                }
            }
        }
        for (; ~u; u = prev[u]) {
            writeln(u, edges[u]);
            int s = min(edges[u][0], edges[u][1]);
            int s1 = max(edges[u][0], edges[u][1]);
            char symbol = inside[u] ? '#' : '%';
            if (s + 1 == s1) {
                result[s / n1 * 2][s % n1 * 2 + 1] = symbol;
            }
            else {
                result[s / n1 * 2 + 1][s % n1 * 2] = symbol;
            }
        }
        for (int i = 0; i < n0 * 2 - 1; ++i) {
            writeln(result[i]);
        }
        writeln();
    }

    bool augment() {
        fill(parent, -1), fill(count, 0);
        for (int i = 0; i < m; ++i) {
            if (inside[i]) {
                merge(edges[i][0], edges[i][1]), count[edges[i][0]]++;
            }
        }
        int rear = 0;
        fill(dist, -1);
        for (int i = 0; i < m; ++i) {
            ok1[i] = !inside[i] && findRoot(edges[i][0]) != findRoot(edges[i][1]);
            ok2[i] = !inside[i] && count[edges[i][0]] < 2;
            if (ok1[i]) {
                dist[i] = 0, prev[i] = -1, queue[rear++] = i;
                if (ok2[i]) {
                    inside[i] = true;
                    return true;
                }
            }
        }
        for (int head = 0; head < rear; ++head) {
            int u = queue[head];
            if (ok2[u]) {
                // debugPlan(prev, u);
                while (~u) {
                    inside[u] ^= 1, u = prev[u];
                }
                return true;
            }
            if (inside[u]) {
                fill(parent, -1);
                for (int i = 0; i < m; ++i) {
                    if (inside[i] && i != u) {
                        merge(edges[i][0], edges[i][1]);
                    }
                }
                for (int v = 0; v < m; ++v) {
                    if (!inside[v] && findRoot(edges[v][0]) != findRoot(edges[v][1])
                            && dist[v] == -1) {
                        dist[v] = dist[u] + 1, prev[v] = u, queue[rear++] = v;
                    }
                }
            }
            else {
                for (int v = 0; v < m; ++v) {
                    if (inside[v] && count[edges[u][0]] - (edges[u][0] == edges[v][0]) < 2
                            && dist[v] == -1) {
                        dist[v] = dist[u] + 1, prev[v] = u, queue[rear++] = v;
                    }
                }
            }
        }
        return false;
    }

    while (augment()) {
        demands--;
    }

    void makePlan() {
        addEdges(0, 0), fill(parent, -1);
        for (int t = 0; t < 2; ++t) {
            for (int i = 0; i < m; ++i) {
                bool connected = findRoot(edges[i][0]) == findRoot(edges[i][1]);
                if (t && !connected) {
                    inside[i] = true;
                }
                if (inside[i] && !connected) {
                    merge(edges[i][0], edges[i][1]);
                }
            }
        }
        auto result = new char[][n0 * 2 - 1];
        for (int i = 0; i < n0 * 2 - 1; ++i) {
            result[i] = new char[n1 * 2 - 1];
            fill(result[i], ' ');
        }
        for (int i = 0; i < n0; ++i) {
            for (int j = 0; j < n1; ++j) {
                result[i * 2][j * 2] = grid[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            if (inside[i]) {
                int s = min(edges[i][0], edges[i][1]);
                int s1 = max(edges[i][0], edges[i][1]);
                if (s + 1 == s1) {
                    result[s / n1 * 2][s % n1 * 2 + 1] = '-';
                }
                else {
                    result[s / n1 * 2 + 1][s % n1 * 2] = '|';
                }
            }
        }
        for (int i = 0; i < n0 * 2 - 1; ++i) {
            writeln(result[i]);
        }
    }

    if (demands) {
        writeln("NO");
    }
    else {
        writeln("YES");
        makePlan();
    }
}

void main() {
    int T = readInt;
    while (T--) {
        work();
    }
}