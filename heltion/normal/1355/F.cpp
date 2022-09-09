#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 811;
int cp[maxn + 1];
constexpr LL inf = 1'000'000'000'000'000'000LL;
LL query(LL x){
    assert(x <= inf);
    cout << "? " << x << endl;
    LL res;
    cin >> res;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> p;
    for(int i = 2; i <= maxn; i += 1){
        if(not cp[i]) p.push_back(i);
        for(int j = i; j <= maxn; j += i)
            cp[j] = 1;
    }
    vector<pair<int, int>> Q;
    for(int L = 0, R = 0; L < (int)p.size(); L = R){
        LL s = 1;
        while(R < (int)p.size() and inf / s >= p[R]) s *= p[R ++];
        Q.push_back({L, R});
    }
    int T;
    for(cin >> T; T; T -= 1){
        LL ans = 1;
        int time = 22;
        for(auto [L, R] : Q) if(time){
            LL q = 1;
            for(int i = L; i < R; i += 1) q *= p[i];
            LL d = query(q);
            time -= 1;
            for(int i = L; i < R; i += 1) if(time) if(d % p[i] == 0){
                LL qq = 1;
                while(qq < 1000000000) qq *= p[i];
                LL dd = query(qq);
                time -= 1;
                LL pans = 1;
                while(dd != 1){
                    dd /= p[i];
                    pans += 1;
                }
                ans *= pans;
            }
        }
        cout << "! " << max(ans * 2, 8LL) << endl;
    }
    return 0;
}