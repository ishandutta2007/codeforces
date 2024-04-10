#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N], b[N];
long long t[N];
vector<int> c[26];

long long get(int x)
{
    long long res = 0;
    while(x > 0){
        res += t[x];
        x -= x & -x;
    }
    return res;
}

void upd(int x, long long y)
{
    while(x <= n){
        t[x] += y;
        x += x & -x;
    }
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - 'a';
    }
    for(int i = 1; i <= n; i++){
        char x;
        cin >> x;
        b[i] = x - 'a';
    }
    for(int i = 0; i < 26; i++){
        c[i].clear();
    }
    for(int i = n; i >= 1; i--){
        c[a[i]].push_back(i);
    }
    for(int i = 0; i <= n + 1; i++){
        t[i] = 0;
    }

    long long res = 1e18, cur = 0;
    for(int i = 1; i <= n; i++){
        for(int x = 0; x < b[i]; x++){
            if(c[x].empty()) continue;
            res = min(res, cur + c[x].back() - 1 - get(c[x].back()));
        }
        if(c[b[i]].empty()){
            break;
        }
        cur += c[b[i]].back() - 1 - get(c[b[i]].back());
        upd(c[b[i]].back(), 1);
        c[b[i]].pop_back();
    }
    cout << (res == 1e18 ? -1 : res) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}