#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

long long inf = 1e18;

int n;
long long a[N];
long long A[N];
pair<long long, long long> t[N][20];
int L[N];
map<long long, vector<int>> v[2];

pair<long long, long long> comb(pair<long long, long long> x, pair<long long, long long> y)
{
        return {min(x.fi, y.fi), min(x.se, y.se)};
}

pair<long long, long long> get(int l, int r)
{
        int g = L[r - l + 1];
        return comb(t[l][g], t[r - (1 << g) + 1][g]);
}

int get(vector<int> &v, int g)
{
        if(v.empty()){
                return 0;
        }
        int l = 0, r = v.size();
        while(l < r){
                int m = (l + r) / 2;
                if(v[m] <= g){
                        r = m;
                } else {
                        l = m + 1;
                }
        }
        return v.size() - l;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                A[i] = a[i] - A[i - 1];

                if(i & 1){
                        t[i][0] = {A[i], inf};
                } else {
                        t[i][0] = {inf, A[i]};
                }
        }

        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n; j++){
                        if(j + (1 << i) - 1 > n){
                                break;
                        }
                        t[j][i] = comb(t[j][i - 1], t[j + (1 << i - 1)][i - 1]);
                }
        }
        v[0].clear();
        v[1].clear();

        long long res = 0;
        for(int i = n; i >= 1; i--){
                int l = i, r = n;
                while(l < r){
                        int m = (l + r) / 2 + 1;
                        auto shit = get(l, m);
                        if(!(i & 1)) {
                                swap(shit.fi, shit.se);
                        }
                        if(shit.fi + A[i - 1] >= 0 && shit.se - A[i - 1] >= 0){
                                l = m;
                        } else{
                                r = m - 1;
                        }
                }

                v[i & 1][A[i]].push_back(i);
                res += get(v[i & 1][-A[i - 1]], l);
                res += get(v[1 - (i & 1)][A[i - 1]], l);
        }

        cout << res << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}