#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150100;

using namespace std;

struct seg
{
        vector < pair < long long, long long > > suf;
        vector < long long > pref;

        void add(long long x)
        {
                suf.push_back({max(x, suf.empty() ? (long long)-1e18: suf.back().fi), x});
        }

        void del()
        {
                if(pref.empty()){
                        while(!suf.empty()){
                                pref.push_back(max(suf.back().se, pref.empty() ? (long long)-1e18 : pref.back()));
                                suf.pop_back();
                        }
                }
                pref.pop_back();
        }

        long long top()
        {
                long long res = -1e18;
                if(!pref.empty()){
                        res = max(res, pref.back());
                }
                if(!suf.empty()){
                        res = max(res, suf.back().fi);
                }
                return res;
        }

        void clear()
        {
                suf.clear();
                pref.clear();
        }
};

int n;
int m;
int D;
int a[N];
int b[N];
int c[N];
long long d[N];
long long f[N];
long long cost[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> D;
        for(int i = 1; i <= m; i++){
                cin >> a[i] >> b[i] >> c[i];
        }
        seg T;
        for(int i = 1; i <= m; i++){
                for(int i = 1; i <= n; i++){
                        cost[i] = 0;
                }
                int j = i;
                while(c[j] == c[i]){
                        for(int h = 1; h <= n; h++){
                                cost[h] += b[j] - abs(a[j] - h);
                        }
                        j += 1;
                }
                int range = min(n * 1ll, 1ll * D * (c[i] - c[i - 1]));
                i = j - 1;
                T.clear();
                for(int j = 1; j <= min(n, range + 1); j++){
                        T.add(d[j]);
                }
                for(int j = 1; j <= n; j++){
                        f[j] = T.top() + + cost[j];
                        if(- range + j >= 1){
                                T.del();
                        }
                        if(range + j + 1 <= n){
                                T.add(d[range + j + 1]);
                        }
                }
                for(int j = 1; j <= n; j++){
                        d[j] = f[j];
                }
        }
        long long res = -1e18;
        for(int i = 1; i <= n; i++){
                res = max(res, d[i]);
        }
        cout << res << "\n";
}