#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int n;
int a[N];
long long T;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> T;
        long long S = 0;
        set < int > f;
        set < pair < int, int > > t;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                S += a[i];
                f.insert(i);
                t.insert({a[i], i});
        }
        int cur = 0;
        long long ans = 0;
        while(S > 0){
                if(S > 0 && (--t.end())->fi > T){
                        S -=(--t.end())->fi;
                        f.erase((--t.end())->se);
                        t.erase(--t.end());
                        continue;
                }
                if(S <= T && S > 0){
                        ans += (T / S) * (long long)f.size();
                        T %= S;
                        continue;
                }
                if(S == 0){
                        break;
                }
                auto p = f.lower_bound(cur + 1);
                if(p == f.end()){
                        p = f.begin();
                }
                cur = *p;
                T -= a[cur];
                ans++;
        }
        cout << ans << "\n";
}