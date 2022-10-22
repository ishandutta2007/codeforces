#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <map>

using namespace std;

const int kInfinite = 1000000000;

class Graph {
  public:
    Graph(const int &size):
        size_(size),
        edges_(size) {
    }

    void addEdge(const int &from, const int &to, const int &capacity) {
        if (capacity_[from][to] == 0) {
            edges_[from].push_back(to);
            edges_[to].push_back(from);
        }

        capacity_[from][to] += capacity;
    }

    int maxFlow(const int &source, const int &sink) {
        int flow = 0;
        while (bfs(source, sink), from_[sink] != -1) {
            for (auto &from : edges_[sink]) {
                if (from_[from] == -1)
                    continue;
                from_[sink] = from;
                int current_flow = numeric_limits<int>::max();

                for (int node = sink; node != source && current_flow; node = from_[node]) {
                    current_flow = min(current_flow, capacity_[from_[node]][node]);
                }

                if (not current_flow)
                    continue;
                for (int node = sink; node != source; node = from_[node]) {
                    capacity_[from_[node]][node] -= current_flow;
                    capacity_[node][from_[node]] += current_flow;
                }
                flow += current_flow;
            }
        }
        return flow;
    }

  private:
    void bfs(const int &source, const int &sink) {
        queue<int> Q;
        Q.push(source);
        from_ = vector<int>(size_, -1);
        from_[source] = source;
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();

            if (node == sink)
                continue;
            for (auto &neighbour : edges_[node])
                if (from_[neighbour] == -1 and capacity_[node][neighbour] > 0) {
                    from_[neighbour] = node;
                    Q.push(neighbour);
                }
        }
    }

    int size_;

    //vector< vector<int> > capacity_;
    map<int, map<int, int> > capacity_;
    vector< vector<int> > edges_;

    vector<int> from_;
};

int main() {
    int N, M, G; cin >> N >> M >> G;

    int source = N + M;
    int sink = N + M + 1;
    Graph R(N + M + 2);

    vector<int> dogSex(N);
    for (int i = 0; i < N; ++i)
        cin >> dogSex[i];

    // source represents the male and sink the female
    for (int i = 0; i < N; ++i) {
        int sexTransformCost; cin >> sexTransformCost;
        if (dogSex[i] == 0)
            R.addEdge(i, sink, sexTransformCost); // to not keep the dog with sink(female) costs
        else
            R.addEdge(source, i, sexTransformCost);
    }

    int answer = 0;
    for (int i = 0; i < M; ++i) {
        int wantedSex, profit, dogs;
        cin >> wantedSex >> profit >> dogs;

        answer += profit; // we calculate how much we might lose
        if (wantedSex == 0)
            R.addEdge(i + N, sink, profit);
        else
            R.addEdge(source, i + N, profit);

        for (int j = 0; j < dogs; ++j) {
            int dog; cin >> dog;
            --dog;

            // flow goes from female to male
            if (wantedSex == 0) // we want an path male -> dog -> person -> female be very expensive, so the person will have to give up on his wish
                R.addEdge(dog, i + N, kInfinite);
            else
                R.addEdge(i + N, dog, kInfinite);
        }

        int is_friend; cin >> is_friend;
        if (is_friend) {
            if (wantedSex == 0)
                R.addEdge(i + N, sink, G);
            else
                R.addEdge(source, i + N, G);
        }
    }

    cout << answer - R.maxFlow(source, sink) << "\n";
}