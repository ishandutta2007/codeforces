#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        string A, B;
        cin >> n >> A >> B;
        int ok = 1;
        map<int, set<int>> mp;
        for(int i = 0; i < n; i += 1) if(A[i] > B[i]) ok = 0;
        else if(A[i] < B[i]) mp[A[i]].insert(B[i]);
        if(not ok) cout << "-1\n";
        else{
            int ans = 0;
            for(int i = 'a'; i < 'a' + 20; i += 1) if(mp.count(i)){
                ans += 1;
                int m = *mp[i].begin();
                for(int j : mp[i]) if(j != m) mp[m].insert(j);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}