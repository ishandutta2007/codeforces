#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

int n, m, i, j, h, k, l, r, s, f, t, cur;
pair < int, pair < int, int > > p[N];
string ans;

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s >> f;
    for(i = 1; i <= m; i++){
        cin >> t >> l >> r;
        p[i] = {t, {l, r}};
    }
    h = 1;
    while(s != f){
        cur++;
        while(h < m && p[h].fi < cur)
            h++;
        t = p[h].fi;
        l = p[h].se.fi;
        r = p[h].se.se;
        if(t == cur && l <= s && s <= r)
            ans += "X";
        else if(s > f && (t != cur || !(l <= s - 1 && s - 1 <= r)))
            ans += "L",
            s--;
        else if(s < f && (t != cur || !(l <= s + 1 && s + 1 <= r)))
            ans += "R",
            s++;
        else
            ans += "X";
    }
    cout << ans << endl;
}