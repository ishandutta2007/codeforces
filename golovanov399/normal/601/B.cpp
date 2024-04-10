#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt(), q = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt();
    vector<int> b(n);
    for (int i = 1; i < n; i++)
        b[i] = abs(a[i] - a[i - 1]);
    vector<pair<int, int>> p(n - 1);
    for (int i = 0; i < n - 1; i++)
        p[i] = {b[i + 1], i + 1};
    sort(all(p));
    while (q--){
        int l = nxt(), r = nxt();
        long long ans = 0;
        long long cur = 0;
        vector<int> st;
        for (int i = l; i < r; i++){
            while (!st.empty() && b[i] > b[st.back()]){
                int qw = (st.size() > 1) ? st[(int)st.size() - 2] : l - 1;
                cur += 1ll * (b[i] - b[st.back()]) * (st.back() - qw);
                st.pop_back();
            }
            st.push_back(i);
            cur += b[i];
            ans += cur;
        }
        cout << ans << "\n";
    }

    return 0;
}