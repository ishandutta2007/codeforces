#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300200;

int n, q;
int a[N];
vector < int > v[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get(int x, int l, int r)
{
        if(v[x].empty()){
                return 0;
        }
        return lower_bound(v[x].begin(), v[x].end(), r + 1) -
                lower_bound(v[x].begin(), v[x].end(), l);
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v[a[i]].push_back(i);
        }

        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                int x = -1, cnt = 0;
                for(int it = 0; it < 30; it++){
                        int pos = abs((int)rng()) % (r - l + 1) + l;
                        int g = get(a[pos], l, r);
                        if(g > cnt){
                                cnt = g;
                                x = a[pos];
                        }
                }

                cout << max(1, cnt - (r - l + 1 - cnt)) << "\n";
        }
}