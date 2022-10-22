#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
//#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define cb(x) (x)=(!(x))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define INFST (0x7f7f7f7f)
#define INFLLST (0x7f7f7f7f7f7f7f7fll)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
typedef complex<ld> base;
const ld EPS = (ld)1e-7;
const ld PI = acos(0) * 2;
bool isZero(const ld& x) { return abs(x) <= EPS; }
int sign(const ld& x) { return isZero(x) ? 0 : (0 < x ? 1 : -1); }
ll gcd(ll a, ll b) { for(;b;a%=b,swap(a,b)){} return abs(a); }
pll operator + (const pll& a, const pll& b) { return pll(a.first+b.first, a.second+b.second); }
pll operator - (const pll& a, const pll& b) { return pll(a.first-b.first, a.second-b.second); }
pll operator * (const pll& a, const ll& b) { return pll(a.first*b, a.second*b); }
ll operator * (const pll& a, const pll& b) { return a.first*b.second - b.first*a.second; }
ll ccw(const pll& a, const pll& b, const pll& c) { return a*b + b*c + c*a; }
void fg(vector<int> G[], int a, int b) { G[a].pb(b); G[b].pb(a); }

void makeE(int);
void makeT(int);
void makeF(int);

const int MAXL = 30;

struct Node {
	string S;
	bool T[8];
};

vector<Node> VE[MAXL], VT[MAXL], VF[MAXL];
bool chkd[3][MAXL];

string Ans[99999];
string Anss[2][99999];

bool isupd(const string& a, const string& b) {
	if(a.empty()) return true;
	if(sz(a) < sz(b)) return false;
	if(a < b) return false;
	return true;
}

int getidx(const Node& v) {
	int ret = 0;
	for(int j = 0; j < 8; j++) {
		ret = (ret<<1) + v.T[j];
	}
	return ret;
}

void makeE(int L) {
	if(L <= 0) return;
	if(chkd[0][L]) return;
	chkd[0][L] = true;

	makeT(L);
	for(auto &v : VT[L]) VE[L].pb(v);

	for(int i = 1; i <= L-2; i++) {
		makeE(i); makeT(L-i-1);
		for(auto &a : VE[i]) for(auto &b : VT[L-i-1]) {
			Node ret;
			ret.S = a.S + "|" + b.S;
			for(int j = 0; j < 8; j++) {
				ret.T[j] = a.T[j] | b.T[j];
			}
			VE[L].pb(ret);
		}
	}

	vector<Node> tmp;
	for(auto &v : VE[L]) {
		int idx = getidx(v);
		if(isupd(Ans[idx], v.S)) {
			Ans[idx] = v.S;
			tmp.pb(v);
		}
	}
	swap(VE[L], tmp);
	clv(tmp);
}
void makeT(int L) {
	if(L <= 0 || chkd[1][L]) return;
	chkd[1][L] = true;

	makeF(L);
	for(auto &v : VF[L]) VT[L].pb(v);

	for(int i = 1; i <= L-2; i++) {
		makeT(i); makeF(L-i-1);
		for(auto &a : VT[i]) for(auto &b : VF[L-i-1]) {
			Node ret;
			ret.S = a.S + "&" + b.S;
			for(int j = 0; j < 8; j++) {
				ret.T[j] = a.T[j] & b.T[j];
			}
			VT[L].pb(ret);
		}
	}
	vector<Node> tmp;
	for(auto &v : VT[L]) {
		int idx = getidx(v);
		if(isupd(Anss[0][idx], v.S)) {
			Anss[0][idx] = v.S;
			tmp.pb(v);
		}
	}
	swap(VT[L], tmp); clv(tmp);
}
void makeF(int L) {
	if(L <= 1 || chkd[2][L]) return;
	chkd[2][L] = true;

	makeF(L-1);
	for(auto &v : VF[L-1]) {
		Node ret; ret.S = "!" + v.S;
		for(int j = 0; j < 8; j++) {
			ret.T[j] = !v.T[j];
		}
		VF[L].pb(ret);
	}

	if(2 < L) {
		makeE(L-2);
		for(auto &v : VE[L-2]) {
			Node ret; ret.S = "(" + v.S + ")";
			for(int j = 0; j < 8; j++) {
				ret.T[j] = v.T[j];
			}
			VF[L].pb(ret);
		}
	}

	vector<Node> tmp;
	for(auto &v : VF[L]) {
		int idx = getidx(v);
		if(isupd(Anss[1][idx], v.S)) {
			Anss[1][idx] = v.S;
			tmp.pb(v);
		}
	}
	swap(VF[L], tmp); clv(tmp);
}

char instr[888];
int N;

void solve() {
	for(scanf("%d", &N); N--;) {
		scanf(" %s", instr);
		int ret = 0;
		for(int i = 0; i < 8; i++) {
			ret = (ret<<1) + (instr[i] - '0');
		}
		puts(Ans[ret].c_str());
	}
}
int main() {
	for(int i = 0; i < 3; i++) VF[1].pb(Node());
	for(int i = 0; i < 3; i++) {
		VF[1][i].S += ('x'+i);
		for(int x = 0; x < 2; x++) for(int y = 0; y < 2; y++) for(int z = 0; z < 2; z++) {
			bool &ret = VF[1][i].T[x*4 + y*2 + z];
			if(0 == i) ret = x;
			else if(1 == i) ret = y;
			else ret = z;
		}
	}
	for(int i = 1; i < MAXL; i++) {
		//printf("start %d\n", i);
		makeE(i);
		//printf("end %d\n", i);
		//printf("size %d = %d\n", i, sz(VE[i]));

		for(auto &v : VE[i]) {
			int idx = 0;
			for(int j = 0; j < 8; j++) {
				idx = (idx<<1) + v.T[j];
			}
			if(Ans[idx].empty() || sz(v.S) < sz(Ans[idx]) || (sz(v.S) == sz(Ans[idx]) && v.S < Ans[idx])) {
				Ans[idx] = v.S;
			}
		}
	}

	solve();
	return 0;
}