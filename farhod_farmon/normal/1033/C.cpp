#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
int d[N];

int get(int x)
{
        if(d[x]){
                return d[x];
        }
        d[x] = 2;
        for(int i = x + a[x]; i <= n; i += a[x]){
                if(a[i] > a[x] && get(i) == 2){
                        d[x] = 1;
                }
        }
        for(int i = x - a[x]; i >= 1; i -= a[x]){
                if(a[i] > a[x] && get(i) == 2){
                        d[x] = 1;
                }
        }
        return d[x];
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                if(get(i) == 1){
                        cout << 'A';
                }
                else{
                        cout << 'B';
                }
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