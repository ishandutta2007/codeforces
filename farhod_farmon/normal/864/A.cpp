#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a = -1, b = -1, c1, c2;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(a == -1 || a == x){
                        a = x;
                        c1++;
                }
                else if(b == -1 || b == x){
                        b = x;
                        c2++;
                }
        }
        if(c1 == c2 && c1 + c2 == n){
                cout << "YES" << "\n";
                cout << a << " " << b << "\n";
        }
        else{
                cout << "NO" << "\n";
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
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}