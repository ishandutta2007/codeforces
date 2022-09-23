#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int d[1 << 3];

void solve()
{
        for(int i = 1; i < 8; i++){
                d[i] = 1e9;
        }
        cin >> n;
        for(int i = 1; i <= n; i++){
                int c;
                string s;
                cin >> c >> s;
                int x = 0;
                for(int j = 0; j < s.size(); j++){
                        x += (1 << (s[j] - 'A'));
                }
                for(int j = 0; j < 8; j++){
                        d[j | x] = min(d[j | x], d[j] + c);
                }
        }
        if(d[7] == 1e9){
                d[7] = -1;
        }
        cout << d[7] << "\n";
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