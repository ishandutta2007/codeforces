#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
using ll = long long;
template<typename T, typename ...Args>
void print(T arg, Args&&... args) {
    cout << arg;
    ((cout << " " << args ), ...);
    cout << "\n";
}
template<typename ...Args>
void read(Args&... args) {
    (cin >> ... >> args);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    read(n);
    vector<int> a(n);
    rep(i,0,n) read(a[i]);
    auto parent = [](int x) {
        int k = 0;
        while((1 << k) < x) ++k;
        return (1 << k) - x;
    };
    using T = tuple<int,int,int>; // val, depth, index
    priority_queue<T> pq;
    rep(i,0,n) pq.push(tuple(a[i],0,i));
    int last = -1, best = -1, acc = -1, accx=-1;
    int bestx=-1, besty=-1;
    while(!pq.empty()) {
        auto [x,d,i] = pq.top(); pq.pop();
        if(x!=last) {
            last = x;
            acc = d;
            accx = i;
        }
        else {
            if(d+acc>best) {
                bestx = accx;
                besty = i;
                best = d+acc;
            }
            if(d>acc) {
                acc = d;
                accx = i;
            }
        }
        last = x;
        if(!pq.empty() && get<0>(pq.top())!=x) {
            pq.push(tuple(parent(last),acc+1,accx));
        }
    }
    print(bestx+1,besty+1,best);
}