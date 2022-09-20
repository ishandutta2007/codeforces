#include <bits/stdc++.h>

#define fi first
#define se second
#define pt pair < double, double >

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        vector < int > p;
        for(int i = 2; i <= 100000; i++){
                bool good = true;
                for(int j = 2; j * j <= i; j++){
                        if(i % j == 0){
                                good = false;
                        }
                }
                if(good){
                        p.push_back(i);
                }
        }

        int t;
        cin >> t;
        while(t--){
                int d;
                cin >> d;
                long long res = 1, j = 0, last = 1;
                for(int i = 0; i < 2; i++){
                        while(p[j] - last < d){
                                j += 1;
                        }
                        last = p[j];
                        res *= p[j];
                }
                cout << res << "\n";
        }
}