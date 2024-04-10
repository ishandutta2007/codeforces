#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
#define int long long

const int MAXN = 1e6 + 7;

int a, b, p, x;

int mod(int n){
    return (n % p + p) % p;
}

int fp(int a, int b){
    if (b == 0) return 1;

    int tmp = fp(a, b / 2);
    if (b % 2 == 0) return mod(tmp * tmp);
    return mod(mod(tmp * tmp) * a);
}

int mydiv(int a, int b){
    return mod(a * fp(b, p - 2));
}

pair <int, int> gcd(int a, int b){
    if (b == 0) return {1, 0};
    
    pair <int, int> tmp = gcd(b, a % b);
    int d = a / b;
    return {tmp.second, tmp.first - d * tmp.second};
}

int mod1(int n, int md){
    return (n % md + md) % md;
}

int getr(int a, int b, int r1, int r2){
    int md = a * b;
    pair <int, int> tmp = gcd(a, b);
    int res = mod1(mod1(a * tmp.first, md) * r2, md) + mod1(mod1(b * tmp.second, md) * r1, md);
    res = mod1(res, md);
    return res;
}

int get(int n, int m, int r){
    return (n / m) + (r <= (n % m));
}

int power[MAXN];
vector <int> get_power[MAXN];

int solve(){
    for (int i = 0; i < p; ++i){
        get_power[i] = {};
    }

    for (int i = 0; i < p - 1; ++i){
        power[i] = fp(a, i);
    }

    for (int i = 0; i < p - 1; ++i){
        get_power[power[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i < p; ++i){
        int wantpr = mydiv(b, i);
        for (int want_power: get_power[wantpr]){ 
            int r = getr(p, p - 1, i, want_power);
            int add = get(x, p * (p - 1), r);
            ans += add;
        }                  
    }

    return ans;    
}

int brute(){
    int ans = 0;
    for (int i = 1; i <= x; ++i){
        if (mod(i * fp(a, i)) == b){
            ++ans;
        }
    }
    return ans;
}

bool is_prime(int n){
    int d = 2;
    while (d * d <= n){
        if (n % d == 0) return false;
        ++d;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    
    cin >> a >> b >> p >> x;
    cout << solve() << '\n';

    return 0;
}