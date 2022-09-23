#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int a[N];
set < pair < long long, int > > s;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s.insert({a[i], i});
        }
        long long ans = 0, g = n + 1;
        if(n % 2 == 0){
                s.insert({0, 0});
        }
        while(s.size() > 1){
                long long cnt = 0;
                for(int i = 0; i < 3; i++){
                        cnt += s.begin()->fi;
                        s.erase(s.begin());
                }
                s.insert({cnt, g});
                ans += cnt;
                g++;
        }
        cout << ans << "\n";
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}