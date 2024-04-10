#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, M, v[110], a1, a2;
int pa, p2a, pb;
vector<int> x;

/**
[A, B)              => 0 1+
[max(2A, B), A+B)   => 0, 1, 2+
[B, A+B)            => % 2

1xx     A
02x     A
01impar 1
01par   A
00par   2 ( todos entre B e 2A )
00impar 1 ( todos entre B e 2A )

**/

inline int find(int a) {
    return lower_bound(x.begin(), x.end(), a) - x.begin();
}

inline int find(int a, int pos) {
    while(pos < x.size() && x[pos] < a) pos++;
    return pos;
}

inline int find2(int a, int pos) {
    while(pos > 0 && x[pos-1] >= a) pos--;
    return pos;
}

inline int evenc(int a, int m, vector<int>& even) {
    ll pos = find(a), quant = even[pos];
    if((x.size() - pos) % 2 == 0) {
        if(pos == x.size()) quant += (m-a);
        else quant += x[pos] - a + 1;
    }
    return quant;
}

void calc(int m) {
    if(x.empty()) return void(a2 += (min(m-1LL, M) - max(m-1-M, 0LL)));
    {
        vector<int> ev;
        for(int X : x) {
            ev.emplace_back(X);
            ev.emplace_back((X + 1)/2);
            ev.emplace_back((X + 1)/2 - 1);
            ev.emplace_back(m - X - 1);
        }
        ev.emplace_back(0);
        if(m > M) {
            ev.emplace_back(m - M - 1);
            ev.emplace_back(m - M);
        }
        ev.emplace_back(m / 2);
        ev.emplace_back(m / 2 - 1);

        sort(ev.begin(), ev.end());
        ev.resize(unique(ev.begin(), ev.end()) - ev.begin());

        vector<int> even(x.size() + 1);
        even[x.size() - 1] = (m - 1 - x.back());
        for(int i = (int)x.size() - 2; i >= 0; i--) {
            if((x.size() - i) % 2) {
                even[i] = even[i+1] + (x[i+1] - x[i]);
            } else even[i] = even[i+1];
        }

        int last = 0, Z = 2;
        pa = p2a = 0;
        pb = x.size();
        for(int X : ev) {
            if(X < 0) continue;
            if(m > M+X) {
                last = X;
                continue;
            }
            if(2 * X == m) Z = 1; /// symmetry
            if(2 * X > m) break;
            pa = find(X, pa), p2a = find(2*X, p2a), pb = find2(m-X, pb);

            if(pa == x.size()) { /// todos [0, A)
                a2 += Z * (X - last);
                last = X;
                continue;
            }
            if(pb > pa) { /// algum em [A, B)
                last = X;
                continue;
            }
            /// [max(2A, B), A+B)
            if(x.size() - max(p2a, pb) >= 2) {
                last = X;
                continue;
            }

            int quant = evenc(m-X, m, even) - evenc(m-last, m, even);
            if(x.size() - max(p2a, pb) == 1) {
                a1 += Z * ((X - last) - quant);
            } else {
                a1 += Z * ((X - last) - quant); /// impar
                a2 += Z * quant; /// par
            }

            last = X;
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &M);
    for(int i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    for(ll amb = 2; amb <= 2*M; amb++) {
        x.clear();
        for(int i = 0; i < n; i++)
            if(v[i] % amb)
                x.push_back(v[i] % amb);
        sort(x.begin(), x.end());
        calc(amb);
    }

    printf("%lld %lld %lld %lld\n", (M*M-a1-a2)/2, (M*M-a1-a2)/2, a1, a2);
    return 0;
}