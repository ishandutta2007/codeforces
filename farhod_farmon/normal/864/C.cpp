#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int a, b, f, k;

void solve()
{
        cin >> a >> b >> f >> k;
        int cnt = 0, h = b;
        while(k > 1){
                k--;
                if(h >= a){
                        if(h - a < a - f){
                                cnt++;
                                h = b - (a - f);
                        }
                        else{
                                h -= a;
                        }
                }
                else if(h >= f){
                        cnt++;
                        h = b - (a - f);
                        if(h < 0){
                                cout << -1 << "\n";
                                return;
                        }
                }
                else{
                        cout << -1 << "\n";
                        return;
                }
                f = a - f;
        }
        if(h < a){
                if(h >= f){
                        cnt++;
                        h = b - (a - f);
                        if(h < 0){
                                cout << -1 << "\n";
                                return;
                        }
                }
                else{
                        cout << -1 << "\n";
                        return;
                }
        }
        cout << cnt << "\n";
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