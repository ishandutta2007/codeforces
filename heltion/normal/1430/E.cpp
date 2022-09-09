#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 2;
int s[maxn];
char t[maxn];
void add(int x, int d){
    for(; x < maxn; x += x & -x) s[x] += d;
}
int sum(int x){
    return x ? s[x] + sum(x - (x & -x)) : 0;
}
vector<int> p[26];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n >> (t + 1);
    for(int i = n; i >= 1; i -= 1){
        add(i, 1);
        p[t[i] - 'a'].push_back(i);
    }
    LL ans = 0;
    for(int i = n; i >= 1; i -= 1){
        int c = t[i] - 'a';
        ans += sum(p[c].back()) - 1;
        add(p[c].back(), -1);
        p[c].pop_back();
    }
    cout << ans;
    return 0;
}