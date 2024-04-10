#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void f(vector<pair<int, int>>& ans, vector<int>& a, int x, int y){
    ans.push_back({x, y});
    a[x] = (a[x] + a[y] - 1) / a[y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //2 4 16 256 65536
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i += 1) a[i] = i;
        vector<pair<int, int>> ans;
        for(int i = 2; i < n; i += 1)
            if(i != 2 and i != 4 and i != 16 and i != 256 and i != 65536) f(ans, a, i, n);
        if(n > 65536){
            f(ans, a, n, 65536);
            f(ans, a, n, 65536);
            f(ans, a, 65536, 256);
            f(ans, a, 65536, 256);
            f(ans, a, 256, 16);
            f(ans, a, 256, 16);
            f(ans, a, 16, 4);
            f(ans, a, 16, 4);
            f(ans, a, 4, 2);
            f(ans, a, 4, 2);
        }
        else if(n > 256){
            f(ans, a, n, 256);
            f(ans, a, n, 256);
            f(ans, a, 256, 16);
            f(ans, a, 256, 16);
            f(ans, a, 16, 4);
            f(ans, a, 16, 4);
            f(ans, a, 4, 2);
            f(ans, a, 4, 2);
        }
        else if(n > 16){
            f(ans, a, n, 16);
            f(ans, a, n, 16);
            f(ans, a, 16, 4);
            f(ans, a, 16, 4);
            f(ans, a, 4, 2);
            f(ans, a, 4, 2);
        }
        else if(n > 4){
            f(ans, a, n, 4);
            f(ans, a, n, 4);
            f(ans, a, 4, 2);
            f(ans, a, 4, 2);
        }
        else{
            f(ans, a, n, 2);
            f(ans, a, n, 2);
        }
        assert(ans.size() <= n + 5);
        for(int i = 1; i <= n; i += 1) if(i != 2) assert(a[i] == 1);
        cout << ans.size() << "\n";
        for(auto [x, y] : ans) cout << x << " " << y << "\n";
    }
    return 0;
}