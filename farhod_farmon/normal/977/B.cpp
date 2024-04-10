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
int d[N];
char c[N];

void solve()
{
        cin >> n;
        int best = 0, h;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                if(i > 1){
                        int x = (c[i - 1] - 'A') * 26 + c[i] - 'A';
                        d[x]++;
                        if(d[x] > best){
                                best = d[x];
                                h = i;
                        }
                }
        }
        cout << c[h - 1] << c[h] << "\n";
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