#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
    
vector<pair<pair<int, int>, int>> ans;

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> s;
    vector<int> t;
    ll sum = 0;
    rep(i,0,n) {
        int x;
        cin >> x;
        sum += x;
        s.emplace_back(x, i);
    }
    rep(i,0,n) {
        int x;
        cin >> x;
        sum -= x;
        t.push_back(x);
    }
    if (sum) {
        cout << "NO" << endl;
        return 0;
    }
    sort(all(s));
    sort(all(t));
    int j = 0;
    rep(i,0,n) {
        while (j < n && s[j].first <= t[j]) {
            ++j;
        }
        if (s[i].first > t[i]) {
            cout << "NO" << endl;
            return 0;
        }
        if (s[i].first < t[i]) {
            int d = min(t[i]-s[i].first, s[j].first-t[j]);
            ans.emplace_back(make_pair(s[i].second, s[j].second), d);
            s[i].first += d;
            s[j].first -= d;
            --i;
        }
    }
    cout << "YES" << endl;
    cout << sz(ans) << endl;
    for (auto it : ans) {
        cout << it.first.first+1 << " " << it.first.second+1 << " " << it.second << endl;
    }
}