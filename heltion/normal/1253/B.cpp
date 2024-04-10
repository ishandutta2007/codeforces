#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
void no(){
    cout << "-1";
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(1, 0);
    set<int> s1, s2;
    for(int i = 1; i <= n; i += 1){
        int a;
        cin >> a;
        if(a > 0){
            if(s2.count(a)) no();
            s1.insert(a);
            s2.insert(a);
        } 
        else{
            if(not s1.count(-a)) no();
            s1.erase(-a);
        }
        if(s1.empty()){
            s2.clear();
            v.push_back(i);
        }
    }
    if(not s1.empty()) no();
    cout << v.size() - 1 << "\n";
    for(int i = 1; i < v.size(); i += 1) cout << v[i] - v[i - 1] << " ";
    return 0;
}