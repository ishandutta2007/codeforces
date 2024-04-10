#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 303;
const int Q = N * 2;
const int mod = 998244353;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > A, B;
                for(int i = 1; i <= n * 2; i++){
                        int x;
                        cin >> x;
                        if(x % 2){
                                A.push_back(i);
                        } else{
                                B.push_back(i);
                        }
                }
                int res = n - 1;
                for(int i = 1; i < (int)A.size() && res; i += 2){
                        res -= 1;
                        cout << A[i - 1] << ' ' << A[i] << "\n";
                }
                for(int i = 1; i < (int)B.size() && res; i += 2){
                        res -= 1;
                        cout << B[i - 1] << ' ' << B[i] << "\n";
                }
        }
}