#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int q;
int NM;
int p[N];
int v[N];
map < string, int > name;

int get(int x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

void solve()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(name.find(s) == name.end())
            name[s] = ++NM;
        p[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int t, x, y;
        string X, Y;
        cin >> t >> X >> Y;
        x = name[X];
        y = name[Y];
        if(t == 1){
            int px = get(x),
                py = get(y);
            if(get(v[px]) == py){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            if(v[px] && v[py])
                p[get(v[px])] = p[get(v[py])];
            else if(v[px])
                v[py] = v[px];
            p[px] = py;
        }
        else{
            int px = get(x),
                py = get(y);
            if(px == py){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            if(v[px])
                p[py] = get(v[px]);
            else
                v[px] = py;
            if(v[py])
                p[px] = get(v[py]);
            else
                v[py] = px;
        }
    }
    for(int i = 1; i <= q; i++){
        int x, y;
        string X, Y;
        cin >> X >> Y;
        x = name[X];
        y = name[Y];
        x = get(x);
        y = get(y);
        if(x == y)
            cout << 1 << endl;
        else if(get(v[x]) == y)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}