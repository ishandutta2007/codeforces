#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 505;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;


void solve()
{
        int a, b, gg = 0;
        cin >> a >> b;
        if(a > b){
                gg = 1;
                swap(a, b);
        }

        int g = 0;
        for(int i = 1; i <= a + b; i++){
                if(1ll * i * (i + 1) / 2 <= a + b){
                        g = i;
                }
                else{
                        break;
                }
        }
        vector < int > v1, v2;
        for(int i = g; i >= 1; i--){
                if(a >= i){
                        a -= i;
                        v1.push_back(i);
                }
                else{
                        v2.push_back(i);
                }
        }

        if(gg)swap(v1, v2);
        cout << v1.size() << endl;
        for(int x: v1){
                cout << x << " ";
        }
        cout << endl;
        cout << v2.size() << endl;
        for(int x: v2){
                cout << x << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}