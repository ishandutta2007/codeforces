#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, sum = 0;
        cin >> n >> x;
        vector<int> v(n);
        for(int& w : v){
            cin >> w;
            sum += w;
        }
        if(sum == x){
            cout << "NO\n";
            continue;
        }
        sort(v.begin(), v.end());
        for(int i = 0, sum = 0; i < n; i += 1){
            sum += v[i];
            if(sum == x){
                swap(v[i], v.back());
                break;
            }
        }
        cout << "YES\n";
        for(int i : v) cout << i << " ";
        cout << "\n";
    }
    return 0;
}