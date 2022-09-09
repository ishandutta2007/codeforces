#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, sum = 0;
        cin >> n;
        vector<int> v(n);
        for(int &x : v){
            cin >> x;
            sum ^= x;
        }
        if(not sum) cout << "DRAW\n";
        else{
            int k = 0;
            for(int i = 0; i < 30; i += 1) if((sum >> i) & 1) k = i;
            int m = 0;
            for(int x : v) m += (x >> k) & 1;
            cout << (m % 4 == 3 and (n & 1) ? "LOSE\n" : "WIN\n");
        }
    }
    return 0;
}