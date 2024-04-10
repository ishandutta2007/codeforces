#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
long double x[N];
long double t[N];
long double r;

void solve()
{
        cin >> n >> r;
        for(int i = 1; i <= n; i++){
                cin >> x[i];
                t[i] = r;
                for(int j = 1; j < i; j++){
                        long double f1 = (r + r) * (r + r) - (x[i] - x[j]) * (x[i] - x[j]);
                        if(f1 < 0){
                                continue;
                        }
                        f1 = sqrt(f1) + t[j];
                        t[i] = max(t[i], f1);
                }
                cout << fixed << setprecision(7) << t[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}