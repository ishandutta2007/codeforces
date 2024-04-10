#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int f(string s) {
    cout << s << endl;
    int w;
    cin >> w;
    if (w == 0)
        exit(0);
    return w;
}
 
int main() {
    const int N = 300;
    int st = f(string(N, 'a'));
    int n = 2 * N - (st + f(string(N, 'b')));
    string t(n, 'a');
    int A = N - st, B = n - A;
    st = B;
    for (int i = 0; i < n - 1; i++) {
        t[i] = 'b';
        if (f(t) > st)
            t[i] = 'a';
        else
            st--;
    }
    if (st)
        t.back() = 'b';
    f(t);
}