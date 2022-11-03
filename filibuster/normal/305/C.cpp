#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    set<int> st;
    int lst = -1;
    while(true) {
//        cout << lst << endl;
        auto it = mp.upper_bound(lst);
        if(it == mp.end())
            break;

        pii p = *it;

        if(p.s % 2 == 1) {
            st.insert(p.f);
        }

        if(p.s > 1)
            mp[p.f + 1] += p.s / 2;
        lst = p.f;
    }



    cout << *st.rbegin() - st.size() + 1 << endl;
}