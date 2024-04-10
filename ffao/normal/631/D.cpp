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

#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);
void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


using namespace std;


typedef vector<int> vi;


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


vi pi(const vector< pair<char, long long> >& s) {
	vi p(s.size());
	for (int i = 1; i < s.size(); i++) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const vector< pair<char, long long> >& s, const vector< pair<char, long long> >& pat) {
    vector< pair<char, long long> > temp = pat;
    temp.push_back({ '?', 0} );
    temp.insert(temp.end(), s.begin(), s.end());
	vi p = pi(temp), res;
	for (int i = (int)p.size() - (int)s.size(); i < p.size(); i++)
		if (p[i] == pat.size()) res.push_back(i - 2 * (int)pat.size());
	return res;
}

int n,m;
void solve()
{
    re(n,m);
    
    pair<char, long long> prev = {'?', 0};
    vector< pair<char, long long> > s;
    REP(i,n) {
        long long occ; char c;
        scanf("%lld-%c", &occ, &c);
        if (c != prev.first) {
            if (prev.first != '?') s.push_back(prev);
            prev = {c,occ};
        }
        else prev.second += occ;
    }
    s.push_back(prev);

    prev = {'?', 0};
    vector< pair<char, long long> > t;
    REP(i,m) {
        long long occ; char c;
        scanf("%lld-%c", &occ, &c);
        if (c != prev.first) {
            if (prev.first != '?') t.push_back(prev);
            prev = {c, occ};
        }
        else prev.second += occ;
    }
    t.push_back(prev);

    if (t.size() >= 3) {
        vector< pair<char, long long> > temp_t = t;
        temp_t.erase(temp_t.begin());
        temp_t.pop_back();
        vi mat = match(s, temp_t);

        int ans = 0;
        for (int m : mat) {
            int past = (m-2) + (int)t.size();
            //ps(s[m-1], t[0], s[past], t.back());
            if (m > 0 && past < s.size() && s[m-1].first == t[0].first && s[m-1].second >= t[0].second && s[past].first == t.back().first && s[past].second >= t.back().second) {
                ans++;
            }
        }
        ps(ans);
        return;
    }

    if (t.size() == 1) {
        long long ans = 0;
        for (int m = 0; m < s.size(); m++) {
            if (s[m].first == t[0].first && s[m].second >= t[0].second) {
                ans += (s[m].second - t[0].second + 1);
            }
        }
        ps(ans);
        return;
    }

    long long ans = 0;
    for (int m = 1; m < s.size(); m++) {
        int past = m;
        if (m > 0 && past < s.size() && s[m-1].first == t[0].first && s[m-1].second >= t[0].second && s[past].first == t.back().first && s[past].second >= t.back().second) {
            ans++;
        }
    }
    ps(ans);
    return;

}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(int x) { printf("%d", x); }
void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}