#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 500500;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;


void solve()
{
        for(int i = 0; i < 2230; i++){
                if(i == 2230 - 1){
                        cout << 5;
                }
                else if(i % 2){
                        cout << 4;
                }
                else{
                        cout << 5;
                }
        }
        cout << "\n";
        for(int i = 0; i < 2230; i++){
                if(i == 2230 - 1){
                        cout << 5;
                }
                else if(i % 2){
                        cout << 5;
                }
                else{
                        cout << 4;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}