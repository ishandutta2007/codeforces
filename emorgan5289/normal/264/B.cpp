#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

template<typename T>
vector<T> uniqueprimefactors(T n) {
    vector<T> out;
    for (T i = 2; i <= n; i++) {
        if (i >= (T)(sqrt(n))+1)
            i = n;
        if (n%i == 0) {
            out.push_back(i);
            while (n%i == 0) n /= i;
        }
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    vector<int> p(100005, 0);
    for (int i = 0; i < n; i++) {
        int x; fin >> x;
        int b = 0;
        for (int j : uniqueprimefactors(x))
            b = max(b, p[j]);
        for (int j : uniqueprimefactors(x))
            p[j] = b+1;
    }
    int out = 1;
    for (auto& x : p)
        out = max(out, x);
    cout << out << "\n";
}