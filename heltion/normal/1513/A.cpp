#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        if(k * 2 + 1 > n) cout << "-1\n";
        else{
            vector<int> p(n);
            int c = n;
            for(int i = 0; i < k; i += 1) p[2 * i + 1] = c --;
            for(int i = 0; i < n; i += 1) if(not p[i]) p[i] = c --;
            for(int i = 0; i < n; i += 1) cout << p[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}