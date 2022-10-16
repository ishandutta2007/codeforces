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
template<class T> void re(std::vector<T>& a);


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);


int n,q;

vector<int> p;
vector<long long> x;
vector<long long> prods;
vector<long long> sumx, sumprods;
const int mod = 998244353;

long long calc(int b, int e) {
    long long t = (sumx[e-1] - sumx[b-1]) % mod;
	t = (t * 1ll * modInv((int)prods[b-1], mod)) % mod;

	long long num = sumprods[e-2];
	if (b-2 >= 0) num = (num - sumprods[b-2]) % mod;
	num = (num * 1ll * modInv((int)prods[b-1], mod)) % mod;

	//printf("b=%d e=%d p0 = %d num = %lld t = %lld\n",b,e,p[0],num,t);
	t = (mod+1-t) % mod;
    long long ret = (num * 1ll * modInv((int)t, mod)) % mod;
    return ret;
}

void solve()
{
    re(n,q);
    p.resize(n); x.resize(n); prods.resize(n+1); sumx.resize(n+1); sumprods.resize(n+1);
    re(p);

    for (int i = 0; i < n; i++) p[i] = (p[i] * 1ll * modInv(100, mod)) % mod;

	prods[0] = 1;
	for (int i = 0; i < n; i++) {
		prods[i+1] = (prods[i] * 1ll * p[i]) % mod;
	}

    for (int i = 0; i < n; i++) x[i] = (prods[i] * 1ll * (1 - p[i])) % mod;

	sumx[0] = 0;
	sumprods[0] = 1;
    for (int i = 0; i < n; i++) {
		sumprods[i+1] = (sumprods[i] + prods[i+1]) % mod;
		sumx[i+1] = (sumx[i] + x[i]) % mod;
	}

    set<int> cps;
    cps.insert(1);
    cps.insert(n+1);
    long long ans = calc(1, n+1);

    for (; q; q--) {
        int t; re(t);

        if (cps.count(t)) {
            cps.erase(t);
            auto it = cps.lower_bound(t);
            int nxt = *it;
            int prv = *(--it);
            ans = (ans - calc(t, nxt)) % mod;
            ans = (ans - calc(prv, t)) % mod;
            ans = (ans + calc(prv, nxt)) % mod;
        }
        else {
            auto it = cps.lower_bound(t);
            int nxt = *it;
            int prv = *(--it);
            ans = (ans + calc(t, nxt)) % mod;
            ans = (ans + calc(prv, t)) % mod;
            ans = (ans - calc(prv, nxt)) % mod;
            cps.insert(t);
        }

        ans = (ans + mod) % mod;
        ps(ans);
    }
}


int main() {


    solve();
}


template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}


/*#include "AhoCorasick.h"

ACnode AhoCorasick::data[2100000];
int AhoCorasick::d_cnt;

ACnode* AhoCorasick::new_node(){
	data[d_cnt].reset();
	return &data[d_cnt++];
}

AhoCorasick::AhoCorasick() {
	reset();
}

void AhoCorasick::reset() {
	d_cnt = 0;
	string_cnt = 0;
	root = new_node();
}

void AhoCorasick::add_string(char* s) {
	ACnode *p = root;
	char c;
	for (int j = 0; (c = s[j]) != '\0'; j++){
		ACnode *it = p->son(c);
		if (it == NULL){
			p->add(c, it = new_node());
		}
		p = it;
	}
	p->o = string_cnt++;
}

void AhoCorasick::compute_fail() {
	std::queue<ACnode*> q;
	for (ACnode *it = root->p; it != NULL; it = it->l){
		q.push(it);
		it->f = root;
	}
	while (!q.empty()){ //calcula os fail
		ACnode *p = q.front();
		q.pop();
		for (ACnode *it = p->p; it != NULL; it = it->l){
			q.push(it);
			ACnode *jt, *kt;
			for (jt = p->f; (kt = jt->son(it -> c)) == NULL; jt = jt->f){
				if (jt == root){
					kt = root;
					break;
				}
			}
			it->f = kt;
			if (it->o == -1){
				it->o = kt->o;
			}
		}
	}
}*/