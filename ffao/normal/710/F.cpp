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


void re(char& x);
void re(char* c);
template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef long long ll;


#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)


struct AhoCorasick {
	enum {alpha = 26, first = 'a'};
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vector<int> backp;
	void insert(string& s, int j) {
		int n = 0;
		trav(c, s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
    AhoCorasick() {}
	AhoCorasick(vector<string>& pat) {
		N.emplace_back(-1);
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	ll find(string word) {
		int n = 0;
		ll count = 0;
		trav(c, word) {
			n = N[n].next[c - first];
			count += N[n].nmatches;
		}
		return count;
	}
};

vector<string> strings[20], deleted_strings[20];
AhoCorasick ahos[20], deleted_ahos[20];

void add(vector<string> strings[], AhoCorasick ahos[], string& s) {
    vector<string> will_insert = {s};
    int i = 0;
    for (; !strings[i].empty(); i++) {
        will_insert.insert(will_insert.end(), all(strings[i]));
        strings[i] = {};
    }

    strings[i] = move(will_insert);
    ahos[i] = AhoCorasick(strings[i]);
}

int q;
char ss[310000];

void solve()
{
    for (re(q); q; q--) {
        int op; string s;
        re(op,ss); s = ss;

        if (op==1) add(strings,ahos,s);
        if (op==2) add(deleted_strings, deleted_ahos, s);
        if (op==3) {
            ll ans = 0;
            for (int i = 0; i < 20; i++) {
                if (!strings[i].empty()) ans += ahos[i].find(s);
                if (!deleted_strings[i].empty()) ans -= deleted_ahos[i].find(s);
            }
            ps(ans);
            fflush(stdout);
        }
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


void re(char& x) { scanf("%c", &x); }
void re(char* c) { scanf("%s", c); }
template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}