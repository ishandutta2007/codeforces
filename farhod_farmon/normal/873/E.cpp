#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3030;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int d[N];
int best[N][N];
pair < int, int > p[N];

pair < pair < int, int >, int > get(int i, int j)
{
        pair < pair < int, int >, int > f;
        f.fi = {p[i].fi - p[i + 1].fi, p[j].fi - p[j + 1].fi};
        int l1 = i, l2 = j - i;
        int l = j + (max(l1, l2) + 1) / 2;
        int r = min(j + min(l1, l2) * 2, n);
        if(l > r){
                f.fi = {-1, -1};
                f.se = -1;
                return f;
        }
        int x = best[l][r];
        f.se = p[x].fi - p[x + 1].fi;
        return f;
}

bool can(int i, int j)
{
        int l1 = i, l2 = j - i;
        if(l1 > l2 * 2 || l2 > l1 * 2){
                return false;
        }
        return true;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> p[i].fi;
                p[i].se = i;
        }
        sort(p + 1, p + n + 1);
        reverse(p + 1, p + n + 1);
        for(int i = 1; i <= n; i++){
                best[i][i] = i;
                for(int j = i + 1; j <= n; j++){
                        int x = best[i][j - 1];
                        if(p[x].fi - p[x + 1].fi < p[j].fi - p[j + 1].fi){
                                best[i][j] = j;
                        }
                        else{
                                best[i][j] = x;
                        }
                }
        }
        int a = 1, b = 2;
        pair < pair < int, int >, int > pp = get(1, 2);
        for(int i = 1; i < n; i++){
                for(int j = i + 1; j < n; j++){
                        if(can(i, j) == false){
                                continue;
                        }
                        pair < pair < int, int >, int > np = get(i, j);
                        if(np > pp){
                                pp = np;
                                a = i;
                                b = j;
                        }
                }
        }
        int l1 = a, l2 = b - a;
        int l = b + (max(l1, l2) + 1) / 2;
        int r = min(b + min(l1, l2) * 2, n);
        int c = best[l][r];
        for(int i = 1; i <= a; i++){
                d[p[i].se] = 1;
        }
        for(int i = a + 1; i <= b; i++){
                d[p[i].se] = 2;
        }
        for(int i = b + 1; i <= c; i++){
                d[p[i].se] = 3;
        }
        for(int i = 1; i <= n; i++){
                if(!d[i]){
                        d[i] = -1;
                }
                cout << d[i] << " ";
        }
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