#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> w(n, vector<int>(n));
    for(int i = 0; i < n; i += 1) cin >> w[i][i];
    for(int i = 0; i + 1 < n; i += 1){
        int k = 0;
        for(int j = i; j < n; j += 1) if(w[j][j - i] == i + 1) k = j;
        for(int j = i; j < k; j += 1) w[j + 1][j - i] = w[j][j - i];
        for(int j = k + 1; j < n; j += 1) w[j][j - i - 1] = w[j][j - i];
    }
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j <= i; j += 1) cout << w[i][j] << " ";
        cout << "\n";
    }
    return 0;
}