#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

struct Train {
    int h, m, ind;

    Train() {};
};

bool cmp(Train a, Train b) {
    if(a.h != b.h)
        return a.h < b.h;
    else
        return a.m < b.m;
}

Train a[N];



int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int n, h, m, k;
    cin >> n >> h >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i].h >> a[i].m;
        a[i].ind = i;
    }

    set<int> st;
    for(int i = 0; i < n; i++) {
        st.insert(a[i].m % (m / 2));
    }

    vector<int> b(st.begin(), st.end());
    vector<int> add(b.size() + 1, 0);

    for(int i = 0; i < n; i++) {
        int p = a[i].m % (m / 2);

        {
            int l = upper_bound(b.begin(), b.end(), p) - b.begin();
            int r = lower_bound(b.begin(), b.end(), p + k) - b.begin();
            add[l]++;
            add[r]--;
        }

        {
            int l = upper_bound(b.begin(), b.end(), p - m / 2) - b.begin();
            int r = lower_bound(b.begin(), b.end(), p - m / 2 + k) - b.begin();
            add[l]++;
            add[r]--;
        }
    }

    vector<int> res(b.size(), 0);
    res[0] = add[0];
    int mn = 0;
    for(int i = 1; i < b.size(); i++) {
        res[i] = res[i - 1] + add[i];
        if(res[i] < res[mn])
            mn = i;
    }

    cout << res[mn] << ' ' << b[mn] << endl;
    for(int i = 0; i < n; i++) {
        int p = a[i].m % (m / 2);
        if(p < b[mn] && b[mn] < p + k || p - m / 2 < b[mn] && p + k - m / 2 > b[mn])
            cout << a[i].ind + 1 << ' ';
    }
}