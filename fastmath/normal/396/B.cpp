#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Frac {
    int a, b;
    Frac(int a_, int b_) {
        a = a_; b = b_;
        if (b < 0) {
            a = a;
            b = b;
        }   
        int d = __gcd(a, b);
        a /= d;
        b /= d;
    }   
    Frac operator +(Frac f) {
        return Frac(a * f.b + f.a * b, b * f.b);
    }   
    Frac operator -(Frac f) {
        return Frac(a * f.b - f.a * b, b * f.b);
    }   
    Frac operator *(Frac f) {
        return Frac(a * f.a, b * f.b);
    }   
    Frac operator /(Frac f) {
        return Frac(a * f.b, b * f.a);
    }   
    Frac operator *(int x) {
        return Frac(a * x, b);
    }   
    Frac operator /(int x) {
        return Frac(a, b * x);
    }   
};

void print(Frac f) {
    cout << f.a << '/' << f.b << '\n';
}   

bool prime(int n) {
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return 0;
    }   
    return 1;
}   

int getl(int x) {
    for (int i = x; ; --i) {
        if (prime(i)) return i;
    }   
}   

int getr(int x) {
    for (int i = x + 1; ; ++i) {
        if (prime(i)) return i;
    }   
}   

Frac get(int x) {
    return Frac(1, getl(x) * getr(x));
}   

void solve() {
    int n;
    cin >> n;

    if (prime(n + 1)) {
        print(Frac(1, 2) - Frac(1, n + 1));
    }   
    else {
        int l = -1, r = -1;
        for (int i = n - 1; ; --i) {
            if (prime(i + 1)) {
                l = i;
                break;
            }   
        }   
        for (int i = n + 1; ; ++i) {
            if (prime(i + 1)) {
                r = i;
                break;
            }   
        }   
        print(Frac(1, 2) - Frac(r - (n - l - 1), (l + 1) * (r + 1)));
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif    
    
    int t;
    cin >> t;
    while (t--) solve();
    
    /*
    Frac sum = {0, 1};
    for (int i = 2; i <= 100; ++i) {
        sum = sum + get(i);
        cout << i << " : ";
        print(Frac(1, 2) - sum);
    }
    */
}