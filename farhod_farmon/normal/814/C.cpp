#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1550;
const long long MX = 1000100;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int f[N];
int d[26][N];
string s;

void build(int x)
{
        for(int i = 1; i <= n; i++){
                f[i] = f[i - 1] + (s[i] == 'a' + x);
        }
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        int l = j - i + 1 - (f[j] - f[i - 1]);
                        d[x][l] = max(d[x][l], j - i + 1);
                }
        }
        for(int i = 1; i <= n; i++){
                d[x][i] = max(d[x][i], d[x][i - 1]);
        }
}

void solve()
{
        cin >> n >> s;
        s = "#" + s;
        for(int i = 0; i < 26; i++){
                build(i);
        }
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                char c;
                int x;
                cin >> x >> c;
                cout << d[c - 'a'][x] << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("cowjog.in");
        //fout("cowjog.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}