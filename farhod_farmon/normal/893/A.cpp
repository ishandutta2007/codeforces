#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 202;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

int n;

void solve()
{
        int p1 = 1, p2 = 2;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(x != p1 && x != p2){
                        cout << "NO" << "\n";
                        return;
                }
                if(x == p1){
                        p2 = 6 - p1 - p2;
                }
                else{
                        p1 = 6 - p1 - p2;
                }
        }
        cout << "YES" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}