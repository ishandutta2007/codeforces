#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int p;
int a[N];

void solve()
{
        int s = 0, s1 = 0, s2 = 0;
        cin >> n >> p;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s2 = (s2 + a[i]) % p;
        }
        for(int i = 1; i < n; i++){
                s1 = (s1 + a[i]) % p;
                s2 = ((s2 - a[i]) % p + p) % p;
                s = max(s, s1 + s2);
        }
        cout << s << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}