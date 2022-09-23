#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int k;
int d;
int f[N];
int s[N];
int a[N];

void solve()
{
        cin >> n >> k >> d;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
                int l = 1, r = i;
                while(l < r){
                        int m = (l + r) / 2;
                        if(a[i] - a[m] <= d){
                                r = m;
                        }
                        else{
                                l = m + 1;
                        }
                }
                if(i - k + 1 >= l){
                        if(l == 1){
                                f[i] = 1;
                        }
                        else if(s[i - k] - s[l - 2] > 0){
                                f[i] = 1;
                        }
                }
                s[i] = s[i - 1] + f[i];
        }
        if(f[n]){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
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