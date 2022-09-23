#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 10100;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
string s;

bool cmp(pair < long long, long long > x, pair < long long, long long > y)
{
        return x.fi * y.se < y.fi * x.se;
}

void solve()
{
        cin >> n;
        long long ans = 0;
        vector < pair < long long, long long > > v;
        for(int i = 1; i <= n; i++){
                long long a = 0, b = 0;
                cin >> s;
                for(int j = 0; j < s.size(); j++){
                        if(s[j] == 'h'){
                                a++;
                                ans += b;
                        }
                        else{
                                b++;
                        }
                }
                v.push_back({a, b});
        }
        sort(v.begin(), v.end(), cmp);
        long long pa = 0, pb = 0;
        for(auto p: v){
                ans += p.fi * pb;
                pa += p.fi;
                pb += p.se;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}