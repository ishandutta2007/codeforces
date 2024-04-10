#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int np[maxn], debug = 0;
vector<int> p, q;
int ans = 1, aha, tot = 0, n = 0, mx = 0;
set<int> s;
void answer(){
    assert(ans >= 1 and ans <= n);
    tot += 1;
    assert(tot <= 10000);
    cout << "C " << ans << endl;
    if(debug){
        assert(ans == mx);
        cout << tot << endl;
    }
    exit(0);
}
int count(int a){
    assert(a >= 1 and a <= n);
    tot += 1;
    assert(tot <= 10000);
    cout << "A " << a << endl;
    if(debug){
        int res = 0;
        for(int x : s) if(x % a == 0) res += 1;
        cout << res << "\n";
        return res;
    }
    int res;
    cin >> res;
    return res;
}
int remove(int a){
    assert(a > 1 and a <= n);
    tot += 1;
    assert(tot <= 10000);
    cout << "B " << a << endl;
    if(debug){
        int res = 0;
        for(auto it = s.begin(); it != s.end();){
            if(*it % a == 0) res += 1;
            if(*it % a == 0 and *it != mx) it = s.erase(it);
            else it = next(it);
        }
        cout << res << "\n";
        return res;
    }
    int res;
    cin >> res;
    return res;
}
void dfs(int L, int R){
    int M = (L + R) >> 1;
    int x = count(1);
    for(int j = L; j <= M; j += 1) remove(q[j]);
    if(x - count(1) == M - L + 1){
        if(M < R) dfs(M + 1, R);
    }
    else for(int j = L; j <= M; j += 1) if(count(q[j])) ans *= q[j];
}
int main(){
    ios::sync_with_stdio(false);
    if(debug){
        srand(time(0));
        n = rand() % 5 + 1;
        mx = rand() % n + 1;
    }
    else cin >> n;
    for(int i = 1; i <= n; i += 1) s.insert(i);
    for(int i = 2; i <= n; i += 1) if(not np[i]){
        p.push_back(i);
        for(int j = i + i; j <= n; j += i) np[j] = 1;
    }
    for(int x : p)
        if((LL)x * x <= n){
            remove(x);
            for(int y = x; y <= n; y *= x)
                if(count(y)) ans *= x;
                else break;
        }
        else q.push_back(x);
    if(not q.empty()){
        if(ans == 1) dfs(0, q.size() - 1);
        else for(int x : q) if((LL)x * ans <= n) if(count(x * ans)) ans *= x;
    }
    answer();
    return 0;
}