#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int x, sum = 0;
        cin >> x;
        for(int i = 1; i; i += 1){
            sum += i;
            if(sum >= x){
                if(sum == x + 1) cout << i + 1 << "\n";
                else cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}