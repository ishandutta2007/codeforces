#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;

void solve()
{
        int a = 0, b = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                if(c == '8'){
                        a++;
                }
                else{
                        b++;
                }
        }
        int ans = 0;
        for(int i = 1; i <= a; i++){
                if((b + a - i) / 10 >= i){
                        ans = i;
                }
        }
        cout << ans << endl;
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