#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        LL N, ans = 0;
        cin >> N;
        for(int i = 0; N; i ^= 1){
            LL M = 0;
            if(N & 1) M = 1;
            else{
                if(N % 4 or N <= 4) M = N / 2;
                else M = 1;
            } 
            if(not i) ans += M;
            N -= M;
        }
        cout << ans << "\n";
    }
    return 0;
}