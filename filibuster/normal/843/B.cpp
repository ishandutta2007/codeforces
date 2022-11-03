#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 5e4 + 13;
const int Q1 = 990;
const int Q2 = 990;

mt19937 rnd(time(0));

pii a[N];

int main() {
    int n, start, x;
    cin >> n >> start >> x;

    for(int i = 0; i < n; i++)
    a[i] = {-1, -1};

    set<int> st;

    st.insert(start - 1);

    cout << "? " << start << endl;
    cin >> a[start - 1].f >> a[start - 1].s;
    a[start - 1].s--;

    while(st.size() < min(Q1, n)) {
        int i = rnd() % n;
        if(st.count(i))
            continue;

        cout << "? " << i + 1 << endl;

        cin >> a[i].f >> a[i].s;
        a[i].s--;

        st.insert(i);
    }

    int mx = -1, ans = -1;
    for(int i = 0; i < n; i++) {
        if(a[i].f == -1)
            continue;

        if(a[i].f >= x) {
            if(ans == -1 || a[ans].f > a[i].f)
                ans = i;
        } else {
            if(mx == -1 || a[mx].f < a[i].f)
                mx = i;
        }
    }

    if(mx == -1) {
        cout << "! " << a[start - 1].f << endl;
        return 0;
    }

    int cur = mx, pr = mx;
    while(true) {
        cout << "? " << cur + 1 << endl;

        cin >> a[cur].f >> a[cur].s;

        if(a[cur].f >= x) {
            cout << "! " << a[cur].f << endl;
            return 0;
        }

        if(a[cur].s == -1) {
            cout << "! " << -1 << endl;
            return 0;
        }

        cur = a[cur].s - 1;
    }
}