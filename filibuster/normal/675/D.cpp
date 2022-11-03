#include <bits/stdc++.h>

#define x first
#define y second
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n, -1), d(n, -1);
    d[0] = 0;

    set<pii> st;
    st.insert({a[0], 0});

    for(int i = 1; i < n; i++) {
        auto it = st.upper_bound({a[i], n});

//        cout << endl << "st : " << endl;
//        for(auto x: st) {
//            cout << x.f << ' ' << x.s << endl;
//        }

        int j = -1;

        if(it == st.end()) {
            it--;
            j = it->s;
        } else if(it == st.begin()){
            j = it->s;
        } else {
            int j1 = it->s;
            it--;
            int j2 = it->s;

            if(d[j1] < d[j2])
                j = j2;
            else
                j = j1;
        }

        p[i] = j;
        d[i] = d[j] + 1;

        st.insert({a[i], i});

        cout << a[j] << ' ';
    }
}