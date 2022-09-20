#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;
const int mod = 998244353;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < pair < int, int > > A, B;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if((i + j) % 2){
                                A.push_back({i, j});
                        } else{
                                B.push_back({i, j});
                        }
                }
        }
        for(int i = 1; i <= n * n; i++){
                int x;
                cin >> x;
                if(x == 3){
                        if(!A.empty()){
                                cout << 1 << " " << A.back().fi << " " << A.back().se << endl;
                                A.pop_back();
                        } else{
                                cout << 2 << " " << B.back().fi << " " << B.back().se << endl;
                                B.pop_back();
                        }
                } else if(x == 1){
                        if(!B.empty()){
                                cout << 2 << " " << B.back().fi << " " << B.back().se << endl;
                                B.pop_back();
                        } else{
                                cout << 3 << " " << A.back().fi << " " << A.back().se << endl;
                                A.pop_back();
                        }
                } else{
                        if(!A.empty()){
                                cout << 1 << " " << A.back().fi << " " << A.back().se << endl;
                                A.pop_back();
                        } else{
                                cout << 3 << " " << B.back().fi << " " << B.back().se << endl;
                                B.pop_back();
                        }
                }
        }
}