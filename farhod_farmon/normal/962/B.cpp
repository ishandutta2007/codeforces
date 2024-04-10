#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int a;
int b;
char c[N];

void solve()
{
        cin >> n >> a >> b;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                if(c[i] != '.'){
                        continue;
                }
                if(a > 0 && (a >= b && c[i - 1] != '1' || c[i - 1] == '2')){
                        c[i] = '1';
                        a--;
                        cnt++;
                }
                else if(b > 0 && (b >= a && c[i - 1] != '2' || c[i - 1] == '1')){
                        c[i] = '2';
                        b--;
                        cnt++;
                }
        }
        c[n + 1] = '\n';
        cout << cnt << "\n";
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