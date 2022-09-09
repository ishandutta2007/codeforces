#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int a[maxn], b[maxn], c[maxn];
int sumb[maxn];
int sumc[maxn + 1];
void add(int x){
    for(x += 1; x < maxn; x += x & -x) sumc[x] += 1;
}
int gsumc(int x){
    int res = 0;
    for(x += 1; x; x -= x & -x) res += sumc[x];
    return res;
}
int n, d;
LL x;
int p[maxn + 1];
LL getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1)
        a[i] = i + 1;
    for(int i = 0; i < n; i = i + 1)
        swap(a[i], a[getNextX() % (i + 1)]);
    for(int i = 0; i < n; i = i + 1) b[i] = i < d;
    for(int i = 0; i < n; i = i + 1)
        swap(b[i], b[getNextX() % (i + 1)]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> d >> x;
    initAB();
    for(int i = 0; i < n; i += 1) p[a[i]] = i;
    partial_sum(b, b + n, sumb);
    set<int> s;
    for(int i = 0; i < n; i += 1) s.insert(i);
    vector<int> v;
    for(int i = 0; i < n; i += 1) if(b[i]) v.push_back(i);
    for(int i = n; i >= 1; i -= 1){
        int L = sumb[n - 1 - p[i]];
        int R = (n - p[i]) - gsumc(n - 1) + gsumc(p[i] - 1);
        if(L <= R){
            for(int x : v) if(x + p[i] >= n) break;
            else if(not c[x + p[i]]){
                c[x + p[i]] = i;
                s.erase(x + p[i]);
                add(x + p[i]);
            }
        }
        else{
            for(auto it = s.lower_bound(p[i]); it != s.end(); )
                if(b[*it - p[i]]){
                    c[*it] = i;
                    add(*it);
                    it = s.erase(it);
                }
                else it = next(it);
        }
    }
    for(int i = 0; i < n; i += 1) cout << c[i] << "\n";
    return 0;
}