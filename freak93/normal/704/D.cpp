#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <limits>
#include <queue>

using namespace std;

class Dinic {
  public:
    Dinic(int size): m_head(size, -1), m_depth(size), m_now(size) {}

    int add_edge(int from, int to, int capacity, int reverse_capacity = 0) {
        int forward = m_edges.size();
        m_edges.emplace_back(Edge{from, to, capacity, m_head[from]});
        m_head[from] = forward;

        m_edges.emplace_back(Edge{to, from, reverse_capacity, m_head[to]});
        m_head[to] = forward + 1;
        return forward;
    }

    int max_flow(int S, int D) {
        int flow = 0;
        while (bfs(S, D)) {
            copy(m_head.begin(), m_head.end(), m_now.begin());
            for (auto f = dfs(S, D); f; f = dfs(S, D))
                flow += f;
        }
        return flow;
    }

    int size() const {
        return m_head.size();
    }

    int flow(int id) const {
        return m_edges[id ^ 1].capacity;
    }

  private:
    struct Edge {
        int from, to, capacity;
        int next = -1;
    };

    bool bfs(int S, int D) {
        m_depth.assign(size(), -1);
        
        m_queue.push(S);
        m_depth[S] = 0;
        while (!m_queue.empty()) {
            int node = m_queue.front();
            m_queue.pop();

            for (int e = m_head[node]; e != -1; e = m_edges[e].next) {
                Edge& edge = m_edges[e];
                if (edge.capacity && m_depth[edge.to] == -1) {
                    m_depth[edge.to] = m_depth[node] + 1;
                    m_queue.push(edge.to);
                }
            }
        }

        return m_depth[D] != -1;
    }

    int dfs(int node, int D, int flow = numeric_limits<int>::max()) {
        if (node == D)
            return flow;

        while (m_now[node] != -1) {
            int e = m_now[node];
            Edge& edge = m_edges[e];

            if (edge.capacity && m_depth[edge.to] == m_depth[node] + 1)
                if (auto f = dfs(edge.to, D, min(flow, edge.capacity)); f != 0) {
                    edge.capacity -= f;
                    m_edges[e ^ 1].capacity += f;
                    return f;
                }

            m_now[node] = edge.next;
        }
        return 0;
    }

    vector<Edge> m_edges;
    vector<int> m_head;

    vector<int> m_depth, m_now;
    queue<int> m_queue;
};

class Graph {
  public:
    Graph(int size): m_size(size) {}

    int add_edge(int from, int to, int min_cap, int max_cap) {
        int id = m_edges.size();
        m_edges.emplace_back(Edge{from, to, min_cap, max_cap});
        return id;
    }

    pair<int, vector<int> > max_flow(int S, int D) {
        Dinic Flow(m_size + 2);
        int S2 = m_size;
        int D2 = S2 + 1;

        vector<int> out(m_size, 0), in(m_size, 0);
        for (auto &edge : m_edges) {
            out[edge.from] += edge.min_cap;
            in[edge.to] += edge.min_cap;
            edge.id1 = Flow.add_edge(edge.from, edge.to, edge.max_cap - edge.min_cap);
        }
        Flow.add_edge(D, S, numeric_limits<int>::max());

        for (int i = 0; i < m_size; ++i) {
            Flow.add_edge(S2, i, in[i]);
            Flow.add_edge(i, D2, out[i]);
        }

        Flow.max_flow(S2, D2);

        Dinic Real(m_size);
        for (auto &edge : m_edges) {
            int f = Flow.flow(edge.id1) + edge.min_cap;
            edge.id2 = Real.add_edge(edge.from, edge.to, edge.max_cap - f, f - edge.min_cap);
        }
        Real.max_flow(S, D);

        int total_flow = 0;
        set< pair<int, int> > edges;
        vector<int> flows;
        flows.reserve(m_edges.size());
        for (auto &edge : m_edges) {
            int f = Real.flow(edge.id2) + edge.min_cap;
            if (edge.from == S)
                total_flow += f;
            flows.emplace_back(f);
        }
        return {total_flow, flows};
    }

  private:
    struct Edge {
        int from, to, min_cap, max_cap, id1 = -1, id2 = -1;
    };

    int m_size;
    vector<Edge> m_edges;
};

int main() {
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    int R, B; cin >> R >> B;

    vector< pair<int, int> > points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    map<int, int> restrictionX, restrictionY;
    for (int i = 0; i < M; ++i) {
        int type, line, limit; cin >> type >> line >> limit;
        map<int, int> & restriction = (type == 1 ? restrictionX : restrictionY);
        if (restriction.count(line)) {
            restriction[line] = min(restriction[line], limit);
        } else {
            restriction[line] = limit;
        }
    }

    char inverted = 0;
    if (R > B) {
        inverted = 'r' ^ 'b';
        swap(R, B);
        for (auto &p : points)
            swap(p.first, p.second);
        swap(restrictionX, restrictionY);
    }

    map<int, int> X, Y;
    int nodes = 0;
    for (auto &p : restrictionX)
        X[p.first] = nodes++;
    for (auto &p : restrictionY)
        Y[p.first] = nodes++;

    for (auto &p : points) {
        if (!X.count(p.first))
            X[p.first] = nodes++;
        if (!Y.count(p.second))
            Y[p.second] = nodes++;
    }

    int S = nodes++;
    int D = nodes++;

    Graph G(nodes);

    vector<int> degrees(nodes, 0);
    vector<int> id(N);
    for (int i = 0; i < N; ++i) {
        int x = X[points[i].first];
        int y = Y[points[i].second];

        id[i] = G.add_edge(x, y, 0, 1);
        ++degrees[x]; ++degrees[y];
    }

    for (auto &p : X) {
        int node = p.second;
        int degree = degrees[node];
        int limit = degree;
        if (restrictionX.count(p.first))
            limit = restrictionX[p.first];

        limit = min(limit, degree);
        if (limit % 2 != degree % 2)
            --limit;
        if (limit < 0) {
            cout << "-1\n";
            return 0;
        }
        G.add_edge(S, node, (degree - limit) / 2, (degree + limit) / 2);
    }


    for (auto &p : Y) {
        int node = p.second;
        int degree = degrees[node];
        int limit = degree;
        if (restrictionY.count(p.first))
            limit = restrictionY[p.first];

        limit = min(limit, degree);
        if (limit % 2 != degree % 2)
            --limit;
        if (limit < 0) {
            cout << "-1\n";
            return 0;
        }
        G.add_edge(node, D, (degree - limit) / 2, (degree + limit) / 2);
    }

    auto [F, flows] = G.max_flow(S, D);
    cout << 1LL * F * R + 1LL * (N - F) * B << "\n";
    for (int i = 0; i < N; ++i) {
        char now;
        if (flows[id[i]])
            now = 'r';
        else 
            now = 'b';
        cout << char(now ^ inverted);
    }
    cout << "\n";
}