#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
pair < int, int > p[N];
map < pair < int, int >, int > used;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int a, b, c;
                char gg;
                cin >> gg >> a >> gg >> b >> gg >> gg >> c;
                a += b;
                int g = __gcd(a, c);
                a /= g; c /= g;
                p[i] = {a, c};
                used[p[i]]++;
        }
        for(int i = 1; i <= n; i++){
                cout << used[p[i]] << " ";
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