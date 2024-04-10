#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
int t[maxn + 1], p[maxn + 1];
vector<int> G[maxn + 1];
set<int> S[maxn + 1];
void no(){
    cout << -1;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1, a, b; i <= m; i += 1){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n; i += 1) cin >> t[i];
    vector<int> v;
    for(int i = 1; i <= n; i += 1) v.push_back(i);
    sort(v.begin(), v.end(), [&](const int& x, const int& y){
        return t[x] < t[y];
    });
    for(int i : v){
        //cout << i << ", " << t[i] << ": ";
        //for(int x : S[i]) cout << x << " ";
        //cout << "\n";
        if((int)S[i].size() + 1 != t[i]) no();
        for(int j : G[i]){
            if(t[j] == t[i]) no();
            if(t[j] > t[i]) S[j].insert(t[i]);
        }
    }
    for(int i : v) cout << i << " ";
    return 0;
}