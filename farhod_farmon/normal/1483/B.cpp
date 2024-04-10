#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 100100;

int n;
int a[N], nxt[N];
bool used[N];
set < int > S;
vector < int > bc;

int get_real(int x)
{
        auto p = S.lower_bound(x + 1);
        if(p == S.end()){
                return *S.begin();
        }
        return *p;
}

int get(int x)
{
        if(used[x]){
                return -1;
        }
        bc.push_back(x);
        used[x] = true;

        x = nxt[x];
        int y = get_real(x);
        if(__gcd(a[x], a[y]) == 1){
                return x;
        }
        return nxt[x] = get(y);
}

void solve()
{
        S.clear();

        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> a[i];

                nxt[i] = i;
                used[i] = false;

                S.insert(i);
        }

        int x = 0;

        vector < int > res;
        while(true){
                for(int y: bc){
                        used[y] = false;
                }
                bc.clear();

                x = get(x);
                if(x == -1){
                        break;
                }
                int y = get_real(x);

                res.push_back(y + 1);
                S.erase(y);
                if(S.empty()){
                        break;
                }

                nxt[x] = x;
                x = get_real(x);
        }
        cout << res.size();
        for(int x: res){
                cout << " " << x;
        }
        cout << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}