#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

void solve()
{
        int n;
        int cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                string s;
                cin >> s;
                if(s == "Tetrahedron")
                {
                        cnt += 4;
                }
                if(s == "Cube")
                {
                        cnt += 6;
                }
                if(s == "Octahedron")
                {
                        cnt += 8;
                }
                if(s == "Dodecahedron")
                {
                        cnt += 12;
                }
                if(s == "Icosahedron")
                {
                        cnt += 20;
                }
        }
        cout << cnt << endl;
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
        return 0;
}