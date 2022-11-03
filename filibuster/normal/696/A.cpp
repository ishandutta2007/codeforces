#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/


bool is_anc(li anc, li v) {
    while(v > anc)
        v /= 2;

    return v == anc;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<li> v, u, w, p;
    map<pair<li, li>, li> mp;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            li x, y, z;
            cin >> x >> y >> z;

            if(x > y)
                swap(x, y);

            v.push_back(x);
            u.push_back(y);
            w.push_back(z);

            while(x != y) {
                if(x > y)
                    swap(x, y);
                mp[{y / 2, y}] += z;
//                cout << "+ " << y / 2 << ' ' << y << ' ' << z << endl;
                y /= 2;
            }

            p.push_back(x);

        } else {
            li x, y;
            cin >> x >> y;

            li res = 0;

            while(x != y) {
                if(x > y)
                    swap(x, y);

                res += mp[{y / 2, y}];

//                for(int j = 0; j < v.size(); j++) {
//                    if(is_anc(p[j], y / 2) && (is_anc(y, v[j]) || is_anc(y, u[j])))
//                        res += w[j];
//                }
                y /= 2;
            }

            cout << res << endl;
        }
    }


}