#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
bool used[1 << 5];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int h = 0;
                for(int j = 0; j < k; j++){
                        int x;
                        cin >> x;
                        h += x << j;
                }
                used[h] = 1;
        }
        for(int i = 0; i < (1 << k); i++){
                for(int j = 0; j < (1 << k); j++){
                        if(used[i] && used[j] && (i & j) == 0){
                                cout << "YES" << "\n";
                                return;
                        }
                }
        }
        cout << "NO" << "\n";
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