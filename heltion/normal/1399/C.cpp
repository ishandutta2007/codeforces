#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k = 0;
        cin >> n;
        vector<int> c(2 * n);
        for(int i = 0, w; i < n; i += 1){
            cin >> w;
            c[w] += 1;
        }
        for(int s = 2; s <= 2 * n; s += 1){
            int pk = 0;
            for(int i = 1; i * 2 < s; i += 1) pk += min(c[i], c[s - i]);
            if(s % 2 == 0) pk += c[s / 2] / 2;
            k = max(k, pk);
        }
        cout << k << "\n";
    }
    return 0;
}