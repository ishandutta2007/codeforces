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
    int i = 0;
    int j = sz(s)-2;
    string ans;
    while (i+2 <= j) {
        map<char, int> cnt;
        cnt[s[i]]++;
        cnt[s[i+1]]++;
        cnt[s[j]]++;
        cnt[s[j+1]]++;
        for (char c = 'a'; c <= 'c'; c++) {
            if (cnt[c] >= 2) {
                ans.push_back(c);
                break;
            }
        }
        i += 2;
        j -= 2;
    }
    cout << ans;
    if (i <= j+1)
        cout << s[i];
    reverse(all(ans));
    cout << ans << endl;
}