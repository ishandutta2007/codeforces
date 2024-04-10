#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];
char c[N];

void solve()
{
        int l = -1e9, r = 1e9;
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = 5; i <= n; i++){
                if(c[i] == '1'){
                        if(c[i - 1] == '0' && c[i - 2] == '0' && c[i - 3] == '0' && c[i - 4] == '0'){
                                l = max(l, a[i] + 1);
                                l = max(l, a[i - 1] + 1);
                                l = max(l, a[i - 2] + 1);
                                l = max(l, a[i - 3] + 1);
                                l = max(l, a[i - 4] + 1);
                        }
                }
                else{
                        if(c[i - 1] == '1' && c[i - 2] == '1' && c[i - 3] == '1' && c[i - 3] == '1'){
                                r = min(r, a[i] - 1);
                                r = min(r, a[i - 1] - 1);
                                r = min(r, a[i - 2] - 1);
                                r = min(r, a[i - 3] - 1);
                                r = min(r, a[i - 4] - 1);
                        }
                }
        }
        cout << l << " " << r << "\n";
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