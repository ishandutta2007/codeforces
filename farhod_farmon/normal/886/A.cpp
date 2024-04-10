#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 30300;
const long long Q = 10010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int s;
int a[7];

void solve()
{
        for(int i = 1; i <= 6; i++){
                cin >> a[i];
                s += a[i];
        }
        for(int i = 1; i <= 6; i++){
                for(int j = i + 1; j <= 6; j++){
                        for(int h = j + 1; h <= 6; h++){
                                if((a[i] + a[j] + a[h]) * 2 == s){
                                        cout << "YES" << "\n";
                                        return;
                                }
                        }
                }
        }
        cout << "NO" << "\n";
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