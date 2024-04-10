#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int a[maxn], p[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = 1; i <= n; i += 1) cin >> b[i];
    vector<int> v;
    for(int i = 1; i <= n; i += 1){
        if(a[i] == b[i]) p[i] = a[i];
        else v.push_back(i);
    }
    if(v.size() == 1){
        set<int> s;
        for(int i = 1; i <= n; i += 1) s.insert(i);
        for(int i = 1; i <= n; i += 1) if(i != v[0]) s.erase(p[i]);
        p[v[0]] = *s.begin();
    }
    else{
        p[v[0]] = a[v[0]], p[v[1]] = b[v[1]];
        set<int> s;
        for(int i = 1; i <= n; i += 1) s.insert(p[i]);
        if(s.size() != n)
            p[v[0]] = b[v[0]], p[v[1]] = a[v[1]];
    }
    for(int i = 1; i <= n; i += 1) cout << p[i] << " ";
    return 0;
}