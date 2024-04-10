#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

/*
1
2
3 4


1
5
1 4 5 9 10

*/

const int N = 3e5 + 13;

int p[N], sz[N], cnt[N];
int fir[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y) {
        cout << 0 << endl;
        exit(0);
        return;
    }

    fir[y] = fir[x];

    if(sz[x] < sz[y])
        swap(x, y);

    sz[x] += sz[y];
    p[y] = x;

}

int prev[N], nxt[N];
int a[N];
vector<int> g[N];
int ans[N];


int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
        nxt[i] = -1;
        fir[i] = i;
//        prev[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if(a[i] != -1)
            g[a[i]].push_back(i);
    }
//    return 0;

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        nxt[x] = y;
//        prev[y] = x;

        unite(x, y);

    }

    for(int i = 0; i < n; i++) {
        int x = getp(i);
        if(a[i] == -1 || getp(a[i]) == x) {
            cnt[x]++;
        }
    }

    set<int> st;
    for(int i = 0; i < n; i++) {
        if(i == p[i] && cnt[i] == sz[i]) {
            st.insert(fir[i]);
        }
    }

    int cur = 0;
    while(!st.empty()) {
        int x = *st.begin();
        st.erase(st.begin());

        while(x != -1) {
            for(auto y : g[x]) {
                cnt[getp(y)]++;
                if(cnt[getp(y)] == sz[getp(y)])
                    st.insert(fir[getp(y)]);
            }
            ans[cur++] = x;
            x = nxt[x];
        }
    }

//    for(int i = 0; i < n; i++) {
//        cout << ans[i] << ' ';
//    }
//    cout <<endl;
//    cout << cur << endl;

    if(cur < n) {

        cout << 0 << endl;
        return 0;
    }

    set<int> s;
    s.insert(-1);
    for(int i = 0; i < n; i++) {
        if(s.count(a[ans[i]]) == 0) {
            cout << 0 << endl;
            return 0;
        }
        s.insert(ans[i]);
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << endl;
}