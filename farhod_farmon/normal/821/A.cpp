#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 55;
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N][N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> a[i][j];
                }
        }
        int ans = 1;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(a[i][j] == 1){
                                continue;
                        }
                        bool ok = false;
                        for(int s = 1; s <= n; s++){
                                for(int t = 1; t <= n; t++){
                                        if(a[i][j] == a[i][s] + a[t][j]){
                                                ok = true;
                                                break;
                                        }
                                }
                        }

                        ans &= ok;
                }
        }
        if(ans){
                cout << "Yes" << "\n";
        }
        else{
                cout << "No" << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}