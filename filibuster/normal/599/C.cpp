#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
7 400000
0 1
0 5
0 6
1 2
1 4
2 3

*/



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    map<int, int> mp;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
        if(mp[a[i]] == 1)
            cnt++;
        else if(mp[a[i]] == 0)
            cnt--;

        mp[b[i]]--;
        if(mp[b[i]] == -1)
            cnt++;
        else if(mp[b[i]] == 0)
            cnt--;

        if(cnt == 0)
            ans++;
    }

    cout << ans << endl;
}