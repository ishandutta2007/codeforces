#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000010;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
int d[N];

void solve()
{
        cin >> n;
        int k = n, g = 1;
        while(k > 3){
                d[k / 2] = max(d[k / 2], 2 * g);
                g *= 2;
                k /= 2;
        }
        d[1] = max(d[1], k * g);
        for(int i = 1; i <= n; i++){
                d[n - i + 1] = max(d[n - i + 1], d[n - i + 2]);
                cout << max(1, d[n - i + 1]) << " ";
        }
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