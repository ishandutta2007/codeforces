#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
int l;
int a[N];

void solve()
{
        cin >> n >> k >> l;
        for(int i = 1; i <= n * k; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n * k + 1);
        int h = 1;
        while(h + 1 <= n * k && a[h + 1] - a[1] <= l){
                h++;
        }
        if(h < n){
                cout << 0 << "\n";
                return;
        }
        if(n == 1){
                cout << a[1] << "\n";
                return;
        }
        long long ans = a[1], pro = k - 1;
        n--;
        for(int i = 2; i <= h; i++){
                if(h - i + 1 == n){
                        ans += a[i];
                        n--;
                }
                else{
                        if(pro){
                                pro--;
                        }
                        else{
                                ans += a[i];
                                pro = k - 1;
                                n--;
                        }
                }
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}