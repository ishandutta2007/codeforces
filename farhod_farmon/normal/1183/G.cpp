#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int c[N];
int d[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < int > a(n);
                set < int > rem;
                for(int i = 0; i < n; i++){
                        int shit;
                        cin >> a[i] >> shit;
                        c[a[i]] += 1;
                        d[a[i]] += shit;
                        rem.insert(i + 1);
                }
                vector < pair < int, int > > v;
                for(int i = 0; i < n; i++){
                        if(c[a[i]]){
                                v.push_back({d[a[i]], c[a[i]]});
                                c[a[i]] = d[a[i]] = 0;
                        }
                }
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());
                int res = 0, SHIT = 0;
                for(int i = 0; i < v.size(); i++){
                        auto p = rem.lower_bound(v[i].se + 1);
                        if(p == rem.begin()){
                                continue;
                        }
                        p--;
                        res += *p;
                        SHIT += min(*p, v[i].fi);
                        rem.erase(p);
                }
                cout << res << " " << SHIT << "\n";
        }
}