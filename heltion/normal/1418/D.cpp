#include<bits/stdc++.h>
using namespace std;
using LL = long long;
multiset<int> d;
set<int> s;
void rm(multiset<int>& s, int m){
    s.erase(s.find(m));
}
void add(int x){
    auto m = s.upper_bound(x);
    if(m != s.end()) d.insert(*m - x);
    if(m != s.begin()) d.insert(x - *prev(m));
    if(m != s.end() and m != s.begin()) rm(d, *m - *prev(m));
    s.insert(x);
}
void rm(int x){
    s.erase(x);
    auto m = s.upper_bound(x);
    if(m != s.end()) rm(d, *m - x);
    if(m != s.begin()) rm(d, x - *prev(m));
    if(m != s.end() and m != s.begin()) d.insert(*m - *prev(m));
}
int f(){
    if(s.size() <= 2) return 0;
    return *prev(s.end()) - *s.begin() - *prev(d.end());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int x; n; n -= 1){
        cin >> x;
        add(x);
    }
    cout << f() << "\n";
    for(int t, x; q; q -= 1){
        cin >> t >> x;
        if(t) add(x);
        else rm(x);
        cout << f() << "\n";
    }
    return 0;
}