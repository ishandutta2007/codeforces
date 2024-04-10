#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > res;
                res.push_back(1);
                int S = 1;
                while(S < n){
                        res.push_back(res.back() * 2);
                        S += res.back();
                }
                S -= n;
                int day = res.size();
                for(int i = 1; i < day; i++){
                        int dif = (1 << (day - i)) - 1;
                        int g = S / dif;
                        S -= g * dif;
                        res[i] -= g;
                        for(int j = i + 1; j < day; j++){
                                res[j] = res[j - 1] * 2;
                        }
                }
                cout << day - 1 << "\n";
                for(int i = 1; i < day; i++){
                        cout << res[i] - res[i - 1] << ' ';
                }
                cout << "\n";
        }
}