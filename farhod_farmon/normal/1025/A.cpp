#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 880;
const long long Q = 10100;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int d[200];

void solve()
{
        cin >> n;
        if(n == 1){
                cout << "Yes" << "\n";
                return;
        }
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                d[c]++;
        }
        for(int i = 1; i < 200; i++){
                if(d[i] > 1){
                        cout << "Yes" << "\n";
                        return;
                }
        }
        cout << "No" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}