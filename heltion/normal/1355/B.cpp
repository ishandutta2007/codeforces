#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int N;
        cin >> N;
        vector<int> e(N);
        for(int &x : e) cin >> x;
        sort(e.begin(), e.end());
        int ans = 0, sum = 0;
        for(int x : e){
            sum += 1;
            while(sum >= x){
                sum -= x;
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}