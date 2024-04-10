#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long

// these to_string headers are taken from tourist on codeforces

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

// #define DEBUG

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("input.in");
#else
#define debug(...)
#define fin cin
#endif

int N;

bool inrange(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fin >> N;
    vector<vector<array<int, 2>>> grid(N, vector<array<int, 2>>(N));
    for (auto& x : grid)
        for (auto& y : x) {
            fin >> y[0] >> y[1];
            y[0]--; y[1]--;
        }

    vector<vector<int>> instr(N, vector<int>(N, ' ')), visited(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j][0] == i && grid[i][j][1] == j) {
                instr[i][j] = 'X';
                array<int, 2> cur = grid[i][j];
                vector<array<int, 2>> stack = {{i, j}};
                visited[i][j] = 1;
                while (!stack.empty()) {
                    int x = stack.back()[0], y = stack.back()[1];
                    stack.pop_back();
                    if (inrange(x+1, y) && !visited[x+1][y] && grid[x+1][y] == cur) {
                        stack.push_back({x+1, y});
                        visited[x+1][y] = 1;
                        instr[x+1][y] = 'U';
                    }
                    if (inrange(x-1, y) && !visited[x-1][y] && grid[x-1][y] == cur) {
                        stack.push_back({x-1, y});
                        visited[x-1][y] = 1;
                        instr[x-1][y] = 'D';
                    }
                    if (inrange(x, y+1) && !visited[x][y+1] && grid[x][y+1] == cur) {
                        stack.push_back({x, y+1});
                        visited[x][y+1] = 1;
                        instr[x][y+1] = 'L';
                    }
                    if (inrange(x, y-1) && !visited[x][y-1] && grid[x][y-1] == cur) {
                        stack.push_back({x, y-1});
                        visited[x][y-1] = 1;
                        instr[x][y-1] = 'R';
                    }
                }
            }

    bool valid = 1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j][0] != -2 && !visited[i][j])
                valid = 0;

    if (!valid) {
        cout << "INVALID\n";
        return 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j][0] == -2 && !visited[i][j]) {
                vector<array<int, 2>> stack = {{i, j}};
                visited[i][j] = 1;
                if (inrange(i+1, j) && !visited[i+1][j] && grid[i+1][j][0] == -2) {
                    stack.push_back({i+1, j});
                    visited[i+1][j] = 1;
                    instr[i+1][j] = 'U';
                    instr[i][j] = 'D';
                }
                else if (inrange(i-1, j) && !visited[i-1][j] && grid[i-1][j][0] == -2) {
                    stack.push_back({i-1, j});
                    visited[i-1][j] = 1;
                    instr[i-1][j] = 'D';
                    instr[i][j] = 'U';
                }
                else if (inrange(i, j+1) && !visited[i][j+1] && grid[i][j+1][0] == -2) {
                    stack.push_back({i, j+1});
                    visited[i][j+1] = 1;
                    instr[i][j+1] = 'L';
                    instr[i][j] = 'R';
                }
                else if (inrange(i, j-1) && !visited[i][j-1] && grid[i][j-1][0] == -2) {
                    stack.push_back({i, j-1});
                    visited[i][j-1] = 1;
                    instr[i][j-1] = 'R';
                    instr[i][j] = 'L';
                } else {
                    cout << "INVALID\n";
                    return 0;
                }
                while (!stack.empty()) {
                    int x = stack.back()[0], y = stack.back()[1];
                    stack.pop_back();
                    if (inrange(x+1, y) && !visited[x+1][y] && grid[x+1][y][0] == -2) {
                        stack.push_back({x+1, y});
                        visited[x+1][y] = 1;
                        instr[x+1][y] = 'U';
                    }
                    if (inrange(x-1, y) && !visited[x-1][y] && grid[x-1][y][0] == -2) {
                        stack.push_back({x-1, y});
                        visited[x-1][y] = 1;
                        instr[x-1][y] = 'D';
                    }
                    if (inrange(x, y+1) && !visited[x][y+1] && grid[x][y+1][0] == -2) {
                        stack.push_back({x, y+1});
                        visited[x][y+1] = 1;
                        instr[x][y+1] = 'L';
                    }
                    if (inrange(x, y-1) && !visited[x][y-1] && grid[x][y-1][0] == -2) {
                        stack.push_back({x, y-1});
                        visited[x][y-1] = 1;
                        instr[x][y-1] = 'R';
                    }
                }
            }

    // for (auto& r : grid) debug(r);
    // for (auto& r : visited) debug(r);
    cout << "VALID\n";
    for (auto& x : instr) {
        for (auto& c : x)
            cout << char(c);
        cout << "\n";
    }
}