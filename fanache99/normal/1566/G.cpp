#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }

private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];

    inline void advance() {
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 100000;
const int EDGES = 3;
const int TOTAL = 50;
const long long INF = 1e18;

map<pair<int, int>, int> idMap;
set<pair<int, int> > adjSmall[1 + MAXN], adjBig[1 + MAXN];
multiset<long long> triples;
set<pair<int, int> > edges;
int from[1 + 5 * MAXN], to[1 + 5 * MAXN], cost[1 + 5 * MAXN];

long long getFirst3(set<pair<int, int> > &s) {
    return (long long) (*s.begin()).first + (long long) (*next(s.begin())).first + (long long) (*next(next(s.begin()))).first;
}

void addTriple(int node) {
    if (adjSmall[node].size() >= 3) {
        long long sum = getFirst3(adjSmall[node]);
        triples.insert(sum);
    }
}

void eraseTriple(int node) {
    if (adjSmall[node].size() >= 3) {
        long long sum = getFirst3(adjSmall[node]);
        assert(triples.find(sum) != triples.end());
        triples.erase(triples.find(sum));
    }
}

void addToMultisets(set<pair<int, int> > &sSmall, set<pair<int, int> >& sBig, int id, int limit) {
    pair<int, int> pr = {cost[id], id};
    if (sSmall.size() < limit) {
        assert(sBig.empty());
        sSmall.insert(pr);
    } else if (pr < (*sSmall.rbegin())) {
        auto x = *sSmall.rbegin();
        sBig.insert(x);
        sSmall.erase(sSmall.find(x));
        sSmall.insert(pr);
    } else {
        sBig.insert(pr);
    }
}

void eraseFromMultisets(set<pair<int, int> > &sSmall, set<pair<int, int> >& sBig, int id, int limit) {
    pair<int, int> pr = {cost[id], id};
    if (sBig.find(pr) != sBig.end()) {
        sBig.erase(sBig.find(pr));
    } else {
        assert(sSmall.find(pr) != sSmall.end());
        sSmall.erase(sSmall.find(pr));
        if (!sBig.empty()) {
            sSmall.insert(*sBig.begin());
            sBig.erase(sBig.begin());
        }
    }
}

void addToNode(int node, int id) {
    eraseTriple(node);
    addToMultisets(adjSmall[node], adjBig[node], id, 3);
    addTriple(node);
}

void eraseFromNode(int node, int id) {
    eraseTriple(node);
    eraseFromMultisets(adjSmall[node], adjBig[node], id, 3);
    addTriple(node);
}

void addEdge(int a, int b, int id) {
    pair<int, int> pr = {cost[id], id};
    if (adjSmall[a].find(pr) != adjSmall[a].end() && adjSmall[b].find(pr) != adjSmall[b].end()) {
        edges.insert(pr);
    }
}

void eraseEdge(int a, int b, int id) {
    pair<int, int> pr = {cost[id], id};
    if (adjSmall[a].find(pr) != adjSmall[a].end() && adjSmall[b].find(pr) != adjSmall[b].end()) {
        //assert(edges.find(pr) != edges.end());
        edges.erase(pr);
    }
}

void removeEdges(int node) {
    for (auto pr : adjSmall[node]) {
        eraseEdge(from[pr.second], to[pr.second], pr.second);
    }
}

void addEdges(int node) {
    for (auto pr : adjSmall[node]) {
        addEdge(from[pr.second], to[pr.second], pr.second);
    }
}

void add(int a, int b, int id) {
    if (a > b) {
        swap(a, b);
    }
    assert(idMap.find({a, b}) == idMap.end());
    idMap[{a, b}] = id;
    removeEdges(a);
    removeEdges(b);
    addToNode(a, id);
    addToNode(b, id);
    addEdges(a);
    addEdges(b);
}

void erase(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    assert(idMap.find({a, b}) != idMap.end());
    int id = idMap[{a, b}];
    idMap.erase({a, b});
    removeEdges(a);
    removeEdges(b);
    eraseFromNode(a, id);
    eraseFromNode(b, id);
    addEdges(a);
    addEdges(b);
}

pair<int, int> temp[1 + TOTAL];

long long compute() {
    long long ans = INF;
    if (!triples.empty()) {
        ans = *triples.begin();
    }
    auto it = edges.begin();
    int cnt = 0;
    while (cnt < TOTAL && it != edges.end()) {
        cnt++;
        temp[cnt] = *it;
        it++;
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            int c = temp[i].first + temp[j].first;
            int a1 = from[temp[i].second], b1 = to[temp[i].second];
            int a2 = from[temp[j].second], b2 = to[temp[j].second];
            if (a1 != a2 && a1 != b2 && b1 != a2 && b1 != b2) {
                ans = min(ans, (long long) c);
            }
        }
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, id = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        id++;
        from[id] = a;
        to[id] = b;
        cost[id] = c;
        add(a, b, id);
    }
    cout << compute() << "\n";
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            id++;
            from[id] = a;
            to[id] = b;
            cost[id] = c;
            add(a, b, id);
        } else {
            int a, b;
            cin >> a >> b;
            erase(a, b);
        }
        cout << compute() << "\n";
    }
    return 0;
}