#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int c[N];
int w[N];
int x[N];
int y[N];
set < pair < int, int > > s;

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(c[i] % 100 == 0){
            x[i] = c[i] / 100;
            continue;
        }
        x[i] = c[i] / 100;
        c[i] = 100 - c[i] % 100;
        m += c[i];
        if(m >= 100){
            m -= 100;
            y[i] = 100 - c[i];
            s.insert({c[i] * w[i], i});
        }
        else{
            x[i]++;
            ans += c[i] * w[i];
            if(!s.empty() && c[i] * w[i] > s.begin()->fi){
                x[i]--;
                y[i] = 100 - c[i];
                ans -= c[i] * w[i];
                ans += s.begin()->fi;
                x[s.begin()->se]++;
                y[s.begin()->se] = 0;
                s.erase(s.begin());
                s.insert({c[i] * w[i], i});
            }
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        cout << x[i] << " " << y[i] << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}