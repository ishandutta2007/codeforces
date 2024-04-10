#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> vp(n + 1), vm(n + 1);
    int sm = 0;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        if(a[i] > 0) vp[a[i]] += 1;
        else{
            vm[-a[i]] += 1;
            sm += 1;
        }
    }
    set<int> ps;
    for(int i = 1; i <= n; i += 1)
        if(vp[i] + sm - vm[i] == m)
            ps.insert(i);
    for(int i = 1; i <= n; i += 1)
        if(a[i] > 0){
            if(not ps.count(a[i])) cout << "Lie\n";
            else if(ps.size() == 1) cout << "Truth\n";
            else cout << "Not defined\n";
        }
        else{
            if(not ps.count(-a[i])) cout << "Truth\n";
            else if(ps.size() == 1) cout << "Lie\n";
            else cout << "Not defined\n";
        }
    return 0;
}