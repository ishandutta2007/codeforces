#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        vector < int > need = {4,8,15,16,23,42};
        vector < int > c((int)need.size(), 0);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                for(int j = 0; j < need.size(); j++){
                        if(need[j] == x){
                                if(j == 0){
                                        c[j] += 1;
                                } else if(c[j - 1]){
                                        c[j - 1] -= 1;
                                        c[j] += 1;
                                }
                        }
                }
        }
        cout << n - 6 * c.back() << "\n";
}