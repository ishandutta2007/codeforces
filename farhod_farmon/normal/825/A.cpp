#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;

void solve()
{
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                if(c == '1'){
                        cnt++;
                }
                else{
                        cout << cnt;
                        cnt = 0;
                }
        }
        cout << cnt;
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
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}