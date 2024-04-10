#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1111;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n / 2; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n / 2 + 1);
        int s1 = 0, s2 = 0;
        for(int i = 1; i <= n / 2; i++){
                s1 += abs(i * 2 - 1 - a[i]);
                s2 += abs(i * 2 - a[i]);
        }
        cout << min(s1, s2) << "\n";
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