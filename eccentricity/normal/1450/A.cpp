#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        string s;
        cin >> n >> s;
        sort(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}