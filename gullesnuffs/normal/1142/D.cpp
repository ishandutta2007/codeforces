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

map<int, int> xinv;
map<pair<int, pair<int, int>>, int> cache;

int main(){
	ios::sync_with_stdio(0);
    vector<ll> x;
    rep(i,1,10)
        x.push_back(i);
    rep(i,0,1e4) {
        xinv[x[i]] = i;
        //cout << i%11 << ": " << x[i] << endl;
        int c=(i+1)%11;
        rep(j,0,c) {
            x.push_back(10*x[i]+j);
        }
        /*if (i == 0 || floor(log(x[i])/log(10)) > floor(log(x[i-1])/log(10)))
            cout << i << ": " << x[i] << endl;*/
    }
    string s;
    cin >> s;
    ll ans = 0;
    rep(i,0,sz(s)) {
        //cerr << "i = " << i << endl;
        if (s[i] != '0') {
            ++ans;
            //cout << s[i] << endl;
        }
        else
            continue;
        if (i == sz(s)-1)
            continue;
        int num = (s[i]-'0')*10+s[i+1]-'0';
        int ind1 = xinv[num/10];
        int ind2 = xinv[num];
        if (ind2 == 0)
            continue;
        ++ans;
        //cout << num << endl;
        assert(xinv[num] != 0);
        int between = ind2-ind1-1;
        int c = ((ind1+1)%11);
        vector<pair<int, pair<int, int>>> keys;
        int lastSuccess = i+1;
        for (int j = i+2; j < sz(s); j++) {
            auto key = make_pair(j, make_pair(between, c));
            if (cache.count(key)) {
                keys.clear();
                ans += cache[key];
                break;
            }
            keys.push_back(key);
            int newBetween = c-(s[j-1]-'0')-1;
            newBetween %= 11;
            if (newBetween < 0)
                newBetween += 11;
            between %= 11;
            for (int k = 0; k < between; k++) {
                newBetween += (c+1+k);
            }
            newBetween %= 11;
            c = (c+between+1)%11;
            between = newBetween;
            between += s[j]-'0';
            between %= 11;
            if (c < 0)
                c += 11;
            if (between < 0)
                between += 11;
            if (s[j]-'0' >= c)
                break;
            if (num < 10000) {
            num = 10*num + s[j]-'0';
            //cerr << "c: " << c << endl;
            //cout << num << endl;
            //cerr << "xinv: " << xinv[num]%11 << endl;
            assert(xinv[num] != 0);
            }
            ++ans;
            lastSuccess = j;
        }
        for (auto key : keys) {
            cache[key] = lastSuccess + 1 - key.first;
        }
    }
    cout << ans << endl;
}