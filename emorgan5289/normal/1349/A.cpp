#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
vector<T> primefactors(T n) {
    vector<T> out;
    for (T i = 2; i <= n; i++) {
        if (i >= (T)(sqrt(n))+1)
            i = n;
        if (n%i == 0) {
            out.push_back(i);
            n /= i;
            i--;
        }
    }
    return out;
}

const int maxn = 200005;
int f1[maxn], f2[maxn], c[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < maxn; i++)
        f1[i] = f2[i] = inf;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        debug(a, primefactors(a));
        int p = -1;
        for (int j = 2; j <= a; j++) {
            if (j >= sqrt(a)+1)
                j = a;
            if (a%j == 0) {
                int k = 0;
                while (a%j == 0) {
                    a /= j; k++;
                }
                if (k < f1[j]) {
                    f2[j] = f1[j]; f1[j] = k;
                } else if (k < f2[j]) {
                    f2[j] = k;
                }
                c[j]++;
            }
        }
    }
    ll out = 1;
    for (ll i = 0; i < maxn; i++) {
        if (c[i] == n-1) {
            for (int j = 0; j < f1[i]; j++)
                out *= i;
        } else if (c[i] == n) {
            for (int j = 0; j < f2[i]; j++)
                out *= i;
        }
    }
    cout << out << "\n";
}