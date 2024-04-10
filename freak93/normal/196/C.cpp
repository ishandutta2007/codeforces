#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second

using namespace std;

class point {
  public:
    int x, y, p;
    bool operator<(const point &that) const {
        if (x != that.x)
            return x < that.x;
        return y < that.y;
    }
};

const int maxn = 1600;

vector< vector<int> > edges;
int father[maxn];
int sum[maxn];

void dfs(int x) {
    for (vector<int>::iterator it = edges[x].begin(); it != edges[x].end(); ++it)
        if (father[x] != *it) {
            father[*it] = x;
            dfs(*it);
            sum[x] += sum[*it];
        }

    sum[x]++;
}

point P[maxn];
int colour[maxn];
int answer[maxn];

class functor {
  public:
    functor(point &_A) {
        A.x = _A.x;
        A.y = _A.y;
        A.p = _A.p;
    }
    
    bool operator()(const point &B, const point &C) {
        long long area = 1LL * A.x * (B.y - C.y) + 1LL * B.x * (C.y - A.y) + 1LL * C.x * (A.y - B.y);
        return area <= 0;
    }

    point A;
};

void solve(int node, int from, int to) {
    //cerr << node << " " << from << " " << to << " (" << P[from].x << ", " << P[from].y << ", " << P[from].p << ")\n";
    sort(P + from + 1, P + to, functor(P[from]));
    answer[P[from].p] = node;
    int last = from + 1;
    for (vector<int>::iterator it = edges[node].begin(); it != edges[node].end(); ++it)
        if (father[node] != *it) {
            solve(*it, last, last + sum[*it]);
            last += sum[*it];
        }
}

int main() {
    int N; cin >> N;
    edges.resize(N);

    for (int i = 1; i < N; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(0);
    for (int i = 0; i < N; ++i)
        cin >> P[i].x >> P[i].y, P[i].p = i;

    sort(P, P + N);
    solve(0, 0, N);
    for (int i = 0; i < N; ++i)
        cout << answer[i] + 1 << " ";
}