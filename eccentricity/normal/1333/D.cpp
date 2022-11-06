#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 3000;
char s[maxn + 2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, sum = 0;
    cin >> n >> k >> (s + 1);
    vector<vector<int>> ans;
    while(true){
        vector<int> v;
        for(int i = 1; i <= n; i += 1)
            if(s[i] == 'R' and s[i + 1] == 'L') v.push_back(i);
        if(v.empty()) break;
        ans.push_back(v);
        sum += v.size();
        for(int i : v) swap(s[i], s[i + 1]);
    }
    if(ans.size() > k or sum < k){
        cout << -1;
        return 0;
    }
    for(auto &v : ans){
        if(sum == k){
            for(int x : v) cout << "1 " << x << "\n";
            k -= v.size();
        }
        else if(sum - (int)v.size() < k - 1){
            int x = sum - k + 1;
            if(x){
                cout << x << " ";
                for(int i = 0; i < x; i += 1)  cout << v[i] << " ";
                cout << "\n";
            }
            for(int i = x; i < (int)v.size(); i += 1) cout << "1 " << v[i] << "\n";
            k -= (int)v.size() - x + 1;
        }
        else{
            cout << v.size() << " ";
            for(int x : v) cout << x << " ";
            cout << "\n";
            k -= 1;
        }
        sum -= v.size();
    }
    assert(k == 0);
    return 0;
}