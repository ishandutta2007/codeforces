#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> visR(n), visC(m);
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));
    vector<set<int>> vs(m);
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < m; j += 1)
            cin >> A[i][j];
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < m; j += 1)
            cin >> B[i][j];
    for(int i = 0; i + 1 < n; i += 1)
        for(int j = 0; j < m; j += 1)
            if(B[i][j] > B[i + 1][j])
                vs[j].insert(i);
    queue<int> q;
    vector<int> v;
    for(int i = 0; i < m; i += 1) if(vs[i].empty()){
        q.push(i);
        visC[i] = 1;
    }
    while(not q.empty()){
        int j = q.front();
        q.pop();
        v.push_back(j);
        for(int i = 0; i + 1 < n; i += 1)
            if(B[i][j] < B[i + 1][j]) if(not visR[i]){
                visR[i] = 1;
                for(int k = 0; k < m; k += 1) if(not visC[k]){
                    vs[k].erase(i);
                    if(vs[k].empty()){
                        q.push(k);
                        visC[k] = 1;
                    }
                }
            }
    }
    stable_sort(A.begin(), A.end(), [&](const vector<int>&p, const vector<int>& q){
        for(int i : v) if(p[i] != q[i]) return p[i] < q[i];
        return false;
    });
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < m; j += 1)
            if(A[i][j] != B[i][j]){
                cout << -1;
                return 0;
            }
    cout << v.size() << "\n";
    reverse(v.begin(), v.end());
    for(int i : v) cout << i + 1 << " ";
    return 0;
}