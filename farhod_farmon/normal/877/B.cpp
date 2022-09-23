#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 5050;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int d[N];
string s;

int geta(int l, int r)
{
        return max(0, d[r] - d[l - 1]);
}

int getb(int l, int r)
{
        return max(0, r - l + 1) - geta(l, r);
}

void solve()
{
        cin >> s;
        n = s.size();
        s = "#" + s;
        for(int i = 1; i <= n; i++){
                d[i] = d[i - 1] + (s[i] == 'a');
        }
        int ans = n - getb(1, n);
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        int l = (i - 1) - getb(1, i - 1);
                        l += (j - i + 1) - geta(i, j);
                        l += (n - j) - getb(j + 1, n);
                        ans = max(ans, l);
                }
        }
        cout << ans << "\n";
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