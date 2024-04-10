#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

void pr(const char *x);
void pr(std::string x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

int t;

char ss[1110000];

string go(const string& ot) {
    if (ot.empty()) return "";

    string cp = ot;
    reverse(all(cp));
    vi f = pi(ot+cp);

    int c = 2*sz(ot)-1;
    while (f[c] > sz(ot)) {
        //dbg(c,f[c-1]);
        c = f[c]-1;
    }
    return ot.substr(0, f[c]);
}

void solve()
{
    for (re(t); t; t--) {
        scanf("%s",ss);
        string s = ss;

        int rem = 0;
        int n = sz(s);

        while (rem < n-rem-1 && s[rem] == s[n-rem-1]) rem++;
        string pref = s.substr(0, rem);
        string suf = s.substr(sz(s)-rem, rem);
        string ot = s.substr(rem, sz(s)-2*rem);
        
        string b = go(ot);
        reverse(all(ot));
        string c = go(ot);
        if (sz(b) < sz(c)) swap(b,c);

        pr(pref,b,suf);
        ps();
    }    
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(const char *x) { printf("%s", x); }
void pr(std::string x) { printf("%s", x.c_str()); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }