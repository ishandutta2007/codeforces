#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

int sum = 0, cnt = 0;
int get(vector <int> a) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
        for (int j = i + 1; j < a.size(); ++j)
            ans += a[i] > a[j];
    return ans;             
}
int n, k;
void gen(vector <int> cur, int i) {
    if (i == k) {
        sum += get(cur);
        ++cnt;
        return;
    }   
    for (int l = 0; l < cur.size(); ++l) {
        for (int r = l; r < cur.size(); ++r) {
            vector <int> a = cur;
            reverse(a.begin() + l, a.begin() + r + 1);
            gen(a, i + 1);
        }   
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    vector <int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    gen(p, 0);
    cout.precision(20);
    cout << (double)sum/cnt<< endl;
}