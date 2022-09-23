#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
long long s[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
                s[i] += s[i - 1];
        }
        for(int i = 1; i <= m; i++){
                long long x, l = 1, r = n;
                cin >> x;
                while(l < r){
                        int m = (l + r) / 2;
                        if(s[m] < x){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
                cout << l << " " << x - s[l - 1] << "\n";
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