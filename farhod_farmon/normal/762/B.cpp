#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll long long

const int N = 100100;
const long long mod = 1e15 + 3;

using namespace std;

ll a, b, c;
ll cnt;
ll ans;
vector < ll > sa, sb;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> c;
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        ll x;
        string s;
        cin >> x >> s;
        if(s == "USB")
            sa.pb(x);
        else
            sb.pb(x);
    }
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    int ha = 0,
        hb = 0;
    for(; ha < sa.size() && a; ha++, a--){
        cnt++;
        ans += sa[ha];
    }
    for(; hb < sb.size() && b; hb++, b--){
        cnt++;
        ans += sb[hb];
    }
    for(; (ha < sa.size() || hb < sb.size()) && c; c--){
        if(hb == sb.size() || ha < sa.size() && sa[ha] < sb[hb]){
            cnt++;
            ans += sa[ha];
            ha++;
        }
        else{
            cnt++;
            ans += sb[hb];
            hb++;
        }
    }
    cout << cnt << " " << ans << endl;
}