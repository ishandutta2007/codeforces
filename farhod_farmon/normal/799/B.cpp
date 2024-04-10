#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int p[N];
int a[N];
int b[N];
set < pair < int, int > > sa[4], sb[4];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> p[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        for(int i = 1; i <= n; i++){
                sa[a[i]].insert({p[i], i});
                sb[b[i]].insert({p[i], i});
        }
        cin >> m;
        for(int i = 1; i <= m; i++){
                int x;
                pair < int, int > mn;
                cin >> x;
                if(sa[x].empty() && sb[x].empty()){
                        cout << -1 << " ";
                        continue;
                }
                if(sa[x].empty() || !sb[x].empty() && sb[x].begin()->fi < sa[x].begin()->fi){
                        mn = *sb[x].begin();
                        sb[x].erase(mn);
                        sa[a[mn.se]].erase(mn);
                }
                else{
                        mn = *sa[x].begin();
                        sa[x].erase(mn);
                        sb[b[mn.se]].erase(mn);
                }
                cout << mn.fi << " ";
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}