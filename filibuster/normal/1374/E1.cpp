#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const li INF = 1e18 + 13;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a, b, c;
    for(int i = 0; i < n; i++) {
        int x, a1, b1;
        cin >> x >> a1 >> b1;

        if(a1 == 0 && b1 == 0)
            continue;

        if(a1 == 1 && b1 == 1)
            c.push_back(x);
        else if(a1 == 1)
            a.push_back(x);
        else
            b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<li> sa(a.size() + 1, 0), sb(b.size() + 1, 0);
    for(int i = 1; i <= a.size(); i++) {
        sa[i] = sa[i - 1] + a[i - 1];
//        cout << "sa " << i << ' ' << sa[i] << endl;
    }

    for(int i = 1; i <= b.size(); i++) {
        sb[i] = sb[i - 1] + b[i - 1];
    }

    li cur = 0;
    li ans = INF;
    for(int i = 0; i <= k; i++) {
        if(a.size() >= k - i && b.size() >= k - i) {
            ans = min(ans, cur + sa[k - i] + sb[k - i]);
//            cout << i << ' ' << cur << ' ' << sa[k - i] << ' ' << sb[k - i] <<' ' << k - i << endl;
        }


        if(i < c.size())
            cur += c[i];
        else
            break;
    }

    cout << (ans < INF ? ans : -1) << endl;
}