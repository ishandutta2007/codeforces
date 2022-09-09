#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200000;
char s[maxn];
struct{
    #define ls (v << 1)
    #define rs (ls | 1)
    #define tm ((tl + tr) >> 1)
    int max[maxn << 2], min[maxn << 2], sum[maxn << 2];
    void add(int v, int tl, int tr, int p, int x){
        if(tl == tr){
            sum[v] += x;
            min[v] = std::min(0, sum[v]);
            max[v] = std::max(0, sum[v]);
        }
        else{
            if(p <= tm) add(ls, tl, tm, p, x);
            else add(rs, tm + 1, tr, p, x);
            sum[v] = sum[ls] + sum[rs];
            min[v] = std::min(min[ls], sum[ls] + min[rs]);
            max[v] = std::max(max[ls], sum[ls] + max[rs]);
        }
    }
}T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, sum = 0;
    string op;
    cin >> n >> op;
    for(int i = 0, p = 1; i < n; i += 1){
        if(op[i] == 'L') p = max(p - 1, 1);
        else if(op[i] == 'R') p += 1;
        else{
            if(s[p] == '(') T.add(1, 1, n, p, -1), sum -= 1;
            if(s[p] == ')') T.add(1, 1, n, p, 1), sum += 1;
            s[p] = op[i];
            if(s[p] == '(') T.add(1, 1, n, p, 1), sum += 1;
            if(s[p] == ')') T.add(1, 1, n, p, -1), sum -= 1;
        }
        if(sum or T.min[1] < 0) cout << "-1\n";
        else cout << T.max[1] << "\n";
    }
}