#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

pi ask(int x) {
    cout << "? " << x << endl;
    int a,b;
    cin >> a >> b;
    return {a,b};
}

int main() {
    int n, start, x;
    cin >> n >> start >> x;
    srand(time(NULL));
    vi v = {};
    for(int i = 1; i <= n; ++i) v.PB(i);
    random_shuffle(v.begin(), v.end());
    pi cur = ask(start);
    if(cur.ST >= x) {
        cout << "! " << cur.ST << endl;
        return 0;
    }
    for(int i = 0; i < min(n, 1000-10); ++i) {
        pi tmp = ask(v[i]);
        if(tmp.ST <= x && tmp.ST > cur.ST) {
            cur = tmp;
            start = v[i];
        }
    }
    if(cur.ST == x) {
        cout << "! " << x << endl;
        return 0;
    }
    int ans = cur.ST;
    while(cur.ND != -1) {
        pi tmp = ask(cur.ND);
        if(tmp.ST >= x) {
            cout << "! " << tmp.ST << endl;
            return 0;
        }
        cur = tmp;
    }
    cout << "! -1" << endl;

}