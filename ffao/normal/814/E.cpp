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


template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);


const int mod = 1000000007;

int fac[110];
int ifac[110];
int pd[51][51][51][51];
int pd2[101][101][101];

int pick(int tot, int want) {
    if (tot < want) return 0;
    int ret = (fac[tot-1] * 1ll * ifac[tot-want]) % mod;
    ret = (ret * 1ll * ifac[2]) % mod;
    return ret;
}

int leave_edges(int two, int three, int desired2, int desired3) { 
	if (desired2 < 0 || desired3 < 0 || two < 0 || three < 0) return 0;
	if (desired2 > 50 || desired3 > 50 || two > 50 || three > 50) return 0;
	if (two == 0 && three == 0) return desired2 == 0 && desired3 == 0;
	
	//printf("leave %d %d %d %d\n", two,three,desired2,desired3);
    int &ret = pd[two][three][desired2][desired3];
    if (ret == -1) {
        ret = 0;
        if (two > 0) {
            ret = (ret + leave_edges(two-1, three, desired2-1, desired3)) % mod;
            ret = (ret + three * 1ll * leave_edges(two, three-1, desired2, desired3)) % mod;
            if (two > 1) ret = (ret + (two-1) * 1ll * leave_edges(two-2, three, desired2, desired3)) % mod;
        }
        else {
			if (three >= 1) ret = (ret + leave_edges(two, three-1, desired2, desired3-1));
            for (int cyc_size = 2; cyc_size <= three; cyc_size++) {
                if (cyc_size >= 3) ret = (ret + pick(three, cyc_size) * 1ll * leave_edges(two, three-cyc_size, desired2, desired3)) % mod;

				int th = (pick(three,cyc_size) * 1ll * cyc_size) % mod;
				ret = (ret + th * 1ll * leave_edges(two, three-cyc_size, desired2-2, desired3)) % mod;
            }
        }
    }
    return ret;
}

int n;
int adj[110];

int rec(int curr, int prev, int prev3) {
	if (curr == n) return (prev == 0);
    if (curr + prev > n) return 0;

    int &ret = pd2[curr][prev][prev3];
    if (ret == -1) {
        ret = 0;

        int two = 0, three = 0;
        for (int i = curr; i < curr+prev; i++) {
            if (adj[i] == 2) two++;
            else three++;
        }

		int tot_edges = two+2*three;

		for (int leave3 = 0; leave3 <= three; leave3++) {
			for (int leave2 = 0; leave2+2*leave3 <= two+2*three; leave2++) {
				ret = (ret + leave_edges(two, three, leave2, leave3) * 1ll * rec(curr+prev, leave2+leave3*2, leave3)) % mod;
			}
		}

		ret = (ret * 1ll * fac[prev]) % mod;
		for (int i = 0; i < prev3; i++) ret = (ret * 1ll * ifac[2]) % mod;
    }

    return ret;
}

void solve()
{
    memset(pd,-1,sizeof(pd));
    memset(pd2,-1,sizeof(pd2));

    fac[0]=ifac[0]=1;
    for (int i = 1; i <= 100; i++) {
        fac[i] = (fac[i-1] * 1ll * i) % mod;
        ifac[i] = (ifac[i-1] * 1ll * modInv(i, mod)) % mod;
    }

    re(n);
    for (int i = 0; i < n; i++) re(adj[i]);

	int ans = rec(1, adj[0], 0);
	ans = (ans * 1ll * ifac[adj[0]]) % mod;
    printf("%d\n",ans);
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