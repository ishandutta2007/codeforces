#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e6 + 13;

/*

3
1 1 1
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    deque<int> deq;
    deq.push_back(0);
    deq.push_back(n - 1);

    vector<bool> used(n, false);
    vector<int> d(n, INF);
    d[0] = d[n - 1] = 1;
    used[0] = used[n - 1] = true;

    for(auto x : mp[1]) {
        if(d[x] == INF) {
            deq.push_front(x);
            d[x] = 1;
            used[x] = true;
        }
    }

    int cur = 0;
    while(!deq.empty()) {
        int v = deq.front();
        deq.pop_front();

//        cout << v << ' ' << d[v] << ' ' << cur << endl;

        if(v + 1 < n && d[v + 1] == INF) {
            d[v + 1] = d[v] + 1;
            deq.push_back(v + 1);
            used[v + 1] = true;
        }

        if(v - 1 >= 0 && d[v - 1] == INF) {
            d[v - 1] = d[v] + 1;
            deq.push_back(v - 1);
            used[v - 1] = true;
        }

        if(cur < d[v]) {
            cur = d[v];
            for(auto x : mp[d[v] + 1]) {
                if(d[x] == INF) {
                    deq.push_back(x);
                    d[x] = d[v] + 1;
                    used[x] = true;
                }
            }
        }
    }

    cout << cur << endl;
}