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


template<class T> void re(std::vector<T>& a);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


int t;
int n;
vector<int> a;


void solve()
{
    for (re(t); t; t--) {
        re(n);
        a.resize(n); re(a);

        int g = 0, s = 0, b = 0;
        for (int i = 0; i+1 < n; i++) if (a[i] != a[i+1]) {
            g = i+1;
            break;
        }

        for (int i = g; i+1 < n; i++) {
            int ts = i - g + 1;
            if (a[i] != a[i+1] && ts > g) {
                s = ts;
                break;
            }
        }

        for (int i = g+s; i+1 < n; i++) {
            int tb = i - (g+s) + 1;
            if (a[i] != a[i+1] && tb > g && (g+s+tb)*2 <= n) {
                b = tb;
            }
        }

        if (b == 0) {
            ps("0 0 0");
        }
        else ps(g,s,b);
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


void pr(int x) { printf("%d", x); }


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