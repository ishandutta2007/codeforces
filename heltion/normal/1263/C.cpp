#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
char s[10][5];
bool check(int i, int n){
    for(int j = 0; j < n; j += 1)
        if(i != j and string(s[i]) == s[j]) return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> v;
        for(int L = 1, R; L <= n; L = R + 1){
            R = n / (n / L);
            v.push_back(n / L);
        }
        v.push_back(0);
        reverse(v.begin(), v.end());
        cout << v.size() << "\n";
        for(int x : v) cout << x << " ";
        cout << "\n";
    }
    return 0;
}