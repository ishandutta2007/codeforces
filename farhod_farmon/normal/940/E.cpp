#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int c;
int L[N];
int f[N][19];
long long a[N];
long long s[N];
long long d[N];

int get(int l, int r)
{
        int g = L[r - l + 1];;
        return min(f[l][g], f[r - (1 << g) + 1][g]);
}

void solve()
{
        cin >> n >> c;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                f[i][0] = a[i];
        }
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        for(int i = 1; i < 19; i++){
                for(int j = 1; j <= n; j++){
                        if(j + (1 << i) - 1 <= n){
                                f[j][i] = min(f[j][i - 1], f[j + (1 << i) / 2][i - 1]);
                        }
                }
        }
        if(c == 1){
                cout << 0 << "\n";
                return;
        }
        set < pair < long long, int > > f;
        f.insert({0, 0});
        for(int i = 1; i <= n; i++){
                s[i] = s[i - 1] + a[i];
                d[i] = f.begin()->fi + s[i];
                if(i - c + 1 >= 0){
                        f.erase({d[i - c + 1] - s[i - c + 1], i - c + 1});
                }
                if(i - c >= 0){
                        d[i] = min(d[i], d[i - c] + s[i] - s[i - c] - get(i - c + 1, i));
                }
                f.insert({d[i] - s[i], i});
        }
        cout << d[n] << "\n";
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