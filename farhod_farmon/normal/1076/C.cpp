#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;


int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int test;
        cin >> test;
        cout << fixed << setprecision(9);
        while(test--){
                long double d;
                cin >> d;
                long double l = 0, r = d;
                for(int i = 0; i < 500; i++){
                        long double m = (r - l) / 3, h1 = l + m, h2 = r - m;
                        h1 = h1 * (d - h1);
                        h2 = h2 * (d - h2);
                        if(fabs(h1 - d) < fabs(h2 - d)){
                                r -= m;
                        }
                        else{
                                l += m;
                        }
                }
                if(fabs((d - l) * l - d) > 1e-6){
                        cout << 'N' << "\n";
                }
                else{
                        cout << 'Y' << " " << d - l << " " << l << "\n";
                }
        }
}