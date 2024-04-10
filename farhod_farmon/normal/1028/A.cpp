#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 500500;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
int m;

void solve()
{
        int l1 = -1, r1, l2 = -1, r2;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        char c;
                        cin >> c;
                        if(c == 'B'){
                                if(l1 == -1){
                                        l1 = i;
                                }
                                r1 = i;
                                if(l2 == -1){
                                        l2 = j;
                                }
                                r2 = j;
                        }
                }
        }
        cout << (l1 + r1) / 2 << " " << (l2 + r2) / 2 << "\n";
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