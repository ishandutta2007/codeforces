#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
long long a[N];
pair < int, int > p[N];

bool cmp(int x, int y)
{
        return p[x].fi < p[y].fi || p[x].se > p[y].se;
}

void solve()
{
        cin >> n;
        vector < int > v;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v.push_back(i);
                long long x = a[i];
                while(x % 2 == 0){
                       p[i].fi += 1;
                       x /= 2;
                }
                while(x % 3 == 0){
                       p[i].se += 1;
                       x /= 3;
                }
        }
        sort(v.begin(), v.end(), cmp);
        for(int x: v){
                cout << a[x] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}