#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
vector<LL> s[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, m, l, r;
    cin >> n >> m >> l >> r;
    for(int i = 1; i <= n; i += 1)
        for(int j = i; j <= n; j += i)
            s[j].push_back(i);
    for(int a = 1; a <= n; a += 1){
        LL b = -1, c = -1;
        LL bl = (l + a - 1) / a, br = min(r / a, m);
        if(bl <= br) for(LL p : s[a]){
            LL qL = a / p + 1, qR = n / p;
            if(qL > qR) continue;
            for(LL q = qL; q <= qR;){
                LL blq = (bl + q - 1) / q * q;
                if(blq <= br){
                    c = p * q;
                    b = blq;
                    break;
                }
                if(q >= bl) break;
                q = (bl + (bl + q - 1) / q - 2) / ((bl + q - 1) / q - 1);
            }
            if(b != -1) break;
        }
        if(b == -1) cout << "-1\n";
        else cout << a << " " << b << " " << c << " " << a * b / c << "\n";
    }
    return 0;
}