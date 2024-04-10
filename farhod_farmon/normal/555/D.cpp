#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int id[N];
pair < int, int > a[N];

int getR(int x, int k)
{
        int l = x, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(a[m + 1].fi - a[x].fi <= k){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        return l;
}

int getL(int x, int k)
{
        int l = 1, r = x;
        while(l < r){
                int m = (l + r) / 2;
                if(a[x].fi - a[m].fi <= k){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        return l;
}

int solve(int x, int k)
{
        while(true){

                int r = getR(x, k);
                int l = getL(r, k - (a[r].fi - a[x].fi));
                if(r == x && l == x){
                        break;
                }

                if(l == x){
                        k %= 2 * (a[r].fi - a[x].fi);
                } else{
                        k -= (a[r].fi - a[x].fi) + (a[r].fi - a[l].fi);
                        x = l;
                }
        }

        return a[x].se;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
                id[a[i].se] = i;
        }

        for(int i = 1; i <= q; i++){
                int x, k;
                cin >> x >> k;
                cout << solve(id[x], k) << "\n";
        }
}