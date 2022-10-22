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
    string s;
    cin >> s;
    bool allSame = true;
    rep(i,0,sz(s)) {
        if (i*2+1 != sz(s) && s[i] != s[0]) {
            allSame = false;
        }
    }
    bool isOddPalindrome = false;
    if (sz(s)%4 == 2) {
        isOddPalindrome = true;
        rep(i,0,sz(s)/4) {
            if (s[i] != s[sz(s)/2-1-i])
                isOddPalindrome = false;
        }
    }
    if (allSame) {
        cout << "Impossible" << endl;
    }
    else {
        rep(i,0,sz(s)) {
            string t = s.substr(i) + s.substr(0, i);
            if (t == s)
                continue;
            bool ok = true;
            rep(j,0,sz(t)) {
                if (t[j] != t[sz(t)-1-j])
                    ok = false;
            }
            if (ok) {
                cout << "1" << endl;
                return 0;
            }
        }
        cout << "2" << endl;
    }
    /*else if (sz(s)%2 == 1 || isOddPalindrome) {
        cout << "2" << endl;
    } else {
        cout << "1" << endl;
    }*/
}