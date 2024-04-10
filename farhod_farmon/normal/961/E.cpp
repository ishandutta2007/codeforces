#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int t[N];

void upd(int x)
{
        while(x < N){
                t[x] += 1;
                x += x & -x;
        }
}

int get(int x)
{
        int cnt = 0;
        while(x > 0){
                cnt += t[x];
                x -= x & -x;
        }
        return cnt;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        long long ans = 0;
        set < pair < int, int > > s;
        for(int i = n; i >= 1; i--){
                while(!s.empty() && (--s.end())->fi >= i){
                        upd((--s.end())->se);
                        s.erase(--s.end());
                }
                int l = i, r = max(i, min(n, a[i]));
                ans += get(r) - get(l);
                s.insert({a[i], i});
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}