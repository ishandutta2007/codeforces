#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int B = 350;
const int K = 15;

li fact[K * 2];

vector<int> get(vector<int> a, li x) {
//    cout << "get " << x << endl;
//    for(auto y : a)
//        cout << y << ' ';
//    cout << endl;
    if(a.size() == 1)
        return a;

    if(fact[a.size()] < x)
        return get(a, x % fact[a.size()]);

    int l = 0, r = a.size();
    while(r - l > 1) {
        int m = (l + r) / 2;

//        cout << l << ' ' << m << ' ' << r << ' ' << fact[a.size() - 1] << endl;

        if(fact[a.size() - 1] * (m) > x)
            r = m;
        else
            l = m;
    }

    swap(a[0], a[l]);
    vector<int> b(a.size() - 1);
    for(int i = 0; i < b.size(); i++)
        b[i] = a[i + 1];

    sort(b.begin(), b.end());

    b = get(b, x - fact[a.size() - 1] * l);

    for(int i = 1; i < a.size(); i++)
        a[i] = b[i - 1];

    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for(int i = 1; i < K * 2; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int n, q;
    cin >> n >> q;

    int k = min(K, n);

    vector<int> b(n - k), a(k);
    for(int i = 0; i < b.size(); i++)
        b[i] = i + 1;

    for(int i = 0; i < k; i++)
        a[i] = i + b.size() + 1;

    vector<li> s(n - k + 1, 0);
    for(int i = 1; i <= b.size(); i++)
        s[i] = s[i - 1] + b[i - 1];

    li cur = 0;
    vector<int> a1 = a;

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int l, r;
            cin >> l >> r;

            l--;

            li ans = 0;
            ans += s[min(r, n - k)] - s[min(l, n - k)];
            for(int j = 0; j < k; j++)
                if(l - n + k <= j && j < r - n + k)
                    ans += a[j];

            cout << ans << '\n';
        } else {
            int x;
            cin >> x;

            cur += x;

            a = get(a1, cur);

//            for(auto y : a)
//                cout << y << ' ';
//            cout << endl;
        }
    }
}