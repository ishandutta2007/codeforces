#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                cin >> n >> k;
                k -= 1;
                bool good = false;
                for(int st: {1, 2}){
                        if(k * st < n && (n - k * st) % 2 == st % 2){
                                good = true;
                                cout << "YES" << "\n";
                                for(int i = 0; i < k; i++){
                                        cout << st << " ";
                                }
                                cout << n - k * st << "\n";
                                break;
                        }
                }
                if(!good){
                        cout << "NO" << "\n";
                }
        }
}