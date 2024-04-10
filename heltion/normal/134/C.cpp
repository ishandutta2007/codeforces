#include<bits/stdc++.h>
using namespace std;
void no(){
    cout << "No";
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s;
    cin >> n >> s;
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> ans;
    for(int i = 1, d; i <= n; i += 1){
        cin >> d;
        pq.push({d, i});
    }
    while(not pq.empty()){
        auto p = pq.top();
        pq.pop();
        auto [d, i] = p;
        if(pq.size() < d) no();
        vector<pair<int, int>> tmp;
        for(int j = 0; j < d; j += 1){
            auto p = pq.top();
            pq.pop();
            ans.push_back({i, p.second});
            p.first -= 1;
            if(p.first) tmp.push_back(p);
        }
        for(auto p : tmp) pq.push(p);
    }
    cout << "Yes\n" << ans.size() << "\n";
    for(auto [x, y] : ans) cout << x << " " << y << "\n";
    return 0;
}