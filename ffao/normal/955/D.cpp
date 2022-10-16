#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()


#define sz(x) (int)(x).size()

vi pi(const string& s) {
	vi p(s.size());
	for (int i = 1; i < s.size(); i++) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

int n,m,k;
bool foundent = false;

void match(const string& s, const string& pat, int* fi) {
	vi p = pi(pat + '\0' + s), res;
    int delta = (int)p.size() - (int)s.size();
	for (int i = delta; i < p.size(); i++) {
        if (i >= delta+k-1) fi[p[i]] = min(fi[p[i]], i-delta);
        else if (p[i] == sz(pat)) foundent = true;
    }

    for (int i = sz(pat); i > 0; i--) {
        fi[p[i-1]] = min(fi[p[i-1]], fi[i]);
    }
}

char ss[610000];
char tt[610000];


int file[610000];
int firi[610000];

void solve()
{   
    re(n,m,k);
    scanf("%s %s", ss, tt);

    string s = ss, t = tt;

    for (int i = 0; i <= s.size(); i++) file[i]=firi[i]=1000000000;

    match(s, t, file);

    reverse(all(s));
    reverse(all(t));

    match(s, t, firi);

    for (int i = 0; i <= k; i++) if (0 <= sz(t)-i && sz(t)-i <= k) {
        if (file[i] < (n-1-firi[sz(t)-i])) {
            ps("Yes");
            ps(file[i]-k+2, n-firi[sz(t)-i]);
            return;
        }
    }

    if (foundent) {
        ps("Yes");
        ps(1, n-k+1);
        return;
    }

    ps("No");
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}