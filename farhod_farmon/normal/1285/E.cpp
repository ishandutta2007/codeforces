#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int A[N];
int R[N];
pair < int, int > a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
        }
        A[0] = 0;
        R[0] = -1e9 - 1;
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
                A[i] = A[i - 1];
                R[i] = R[i - 1];
                if(R[i] >= a[i].fi){
                        R[i] = max(R[i], a[i].se);
                } else{
                        R[i] = a[i].se;
                        A[i] += 1;
                }
        }
        int res = 0;
        vector < pair < int, int > > v;
        for(int i = n; i >= 1; i--){
                if(i < n){
                        int l = 0, r = v.size();
                        while(l < r){
                                int m = (l + r) / 2;
                                if(R[i - 1] < v[m].fi){
                                        l = m + 1;
                                } else{
                                        r = m;
                                }
                        }
                        res = max(res, A[i - 1] + l);
                }
                while(!v.empty() && a[i].se >= v.back().se){
                        v.pop_back();
                }
                if(v.empty() || a[i].se < v.back().fi){
                        v.push_back(a[i]);
                } else{
                        v.back().fi = a[i].fi;
                }
        }
        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}