#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1555;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int a, b;

void solve()
{
        cin >> a >> b;
        for(int i = 1; ; i++){
                if(i % 2){
                        if(a >= i){
                                a -= i;
                        }
                        else{
                                cout << "Vladik" << endl;
                                break;
                        }
                }
                else{
                        if(b >= i){
                                b -= i;
                        }
                        else{
                                cout << "Valera" << endl;
                                break;
                        }
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}