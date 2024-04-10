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

int main(){
	ios::sync_with_stdio(0);
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    vi a(m);
    rep(i,0,m)
        cin >> a[i];
    map<int, int> need;
    rep(i,0,s) {
        int b;
        cin >> b;
        ++need[b];
    }
    if (s > k) {
        cout << "-1" << endl;
        return 0;
    }
    map<int, int> needOrig = need;
    int l = 0;
    int r = 0;
    int needNum = sz(need);
    while (r < m) {
        --need[a[r]];
        if (!need[a[r]]) {
            --needNum;
        }
        ++r;
        while (r-l > k && need[a[l]] < 0) {
            need[a[l]]++;
            l++;
        }
        if (needNum)
            continue;
        int numBefore = l/k;
        int numAfter = (m-r)/k;
        while (numBefore+numAfter+1 > n) {
            if (numAfter)
                --numAfter;
            else
                --numBefore;
        }
        //assert(numBefore >= 0 && numAfter >= 0);
        if (r-l >= k && numBefore >= 0 && numAfter >= 0 && numBefore+numAfter >= n-1) {
            vi ans;
            rep(i,numBefore*k,l)
                ans.push_back(i);
            rep(i,r,m-numAfter*k)
                ans.push_back(i);
            need=needOrig;
            int remove = r-l-k;
            assert(remove >= 0);
            int couldRemove = 0;
            int couldNotRemove = 0;
            rep(i,l,r) {
                if (need[a[i]]) {
                    couldNotRemove++;
                    --need[a[i]];
                }
                else {
                    couldRemove++;
                    if(remove > 0) {
                        ans.push_back(i);
                        --remove;
                    }
                }
            }
            assert(couldNotRemove == s);
            assert(couldRemove >= r-l-k);
            assert(remove == 0);
            sort(all(ans));
            cout << sz(ans) << endl;
            /*rep(i,0,sz(ans)-1)
                assert(ans[i] != ans[i+1]);*/
            for (int x : ans)
                cout << x+1 << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}