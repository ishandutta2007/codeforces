#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 1024;
const int MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
string a, b, s, t;

void solve()
{
    cin >> a >> b >> n;
    cout << a << " " << b << endl;
    for(int i = 1; i <= n; i++){
        cin >> s >> t;
        if(s == a)
            a = t;
        else
            b = t;
        cout << a << " " << b << endl;
    }
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
}