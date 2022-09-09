#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, a;
        cin >> n >> a;
        int L = n + 1, D = 0, C = 0, CC = 1;
        for(int i = 2; i <= n; i += 1){
            cin >> a;
            if(a < L){
                if(C) C -= 1;
                else{
                    D += 1;
                    C = CC - 1;
                    CC = 0;
                }
            }
            CC += 1;
            L = a;
        }
        cout << D << "\n";
    }
    return 0;
}