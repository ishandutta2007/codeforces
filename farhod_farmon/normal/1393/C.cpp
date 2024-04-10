#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N], b[N];
vector < int > to_add[N];
set < pair < int, int > > S;

bool can(int k)
{
        S.clear();
        for(int i = 0; i <= n; i++){
                to_add[i].clear();
                b[i] = a[i];
                if(b[i] > 0){
                        S.insert({b[i], i});
                }
        }
        for(int i = 1; i <= n; i++){
                if(S.empty()) return false;
                int j = (--S.end())->se;
                S.erase(--S.end());
                b[j] -= 1;
                if(b[j] > 0 && i + k <= n){
                        to_add[i + k].push_back(j);
                }
                for(int x: to_add[i]){
                        S.insert({b[x], x});
                }
        }
        return true;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++) a[i] = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x] += 1;
        }
        int l = 0, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        cout << l << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}