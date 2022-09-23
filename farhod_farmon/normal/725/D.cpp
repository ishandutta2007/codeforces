#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

int n;
int ans;
pair < long long, long long > p[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i].fi >> p[i].se;
    sort(p + 2, p + n + 1);
    set < pair < long long, int > > s;
    int j = n;
    ans = n;
    for(int i = 1; i <= n; i++){
        while(j > 1 && p[j].fi > p[1].fi){
            s.insert({p[j].se - p[j].fi + 1, j});
            j--;
        }
        ans = min(ans, (int)s.size() + 1);
        if(s.empty())
            break;
        if(p[1].fi >= s.begin()->fi){
            p[1].fi -= s.begin()->fi;
            s.erase(s.begin());
        }
    }
    cout << ans << endl;
}