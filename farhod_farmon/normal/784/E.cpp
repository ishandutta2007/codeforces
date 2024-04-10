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

int a[20];

void solve()
{
        cin >> a[1] >> a[2] >> a[3] >> a[4];
        a[5] = a[1] ^ a[2];
        a[6] = a[3] | a[4];
        a[7] = a[2] & a[3];
        a[8] = a[1] ^ a[4];
        a[9] = a[5] & a[6];
        a[10] = a[7] | a[8];
        a[11] = a[9] ^ a[10];
        cout << a[11];
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