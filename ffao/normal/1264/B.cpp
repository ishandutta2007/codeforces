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


int a,b,c,d;
vi ans;

void solve()
{
    re(a,b,c,d);

    int r1 = b - a;
    int r2 = c - d;

    for (int i = 0; i < a; i++) {
        if (i != 0 || r1 > r2) {
            ans.push_back(1);
            b--;
        }
        ans.push_back(0);
    }
    a = 0;

    if ((!ans.empty() || r1 > r2) && b) {
        ans.push_back(1);
        b--;
    }

    if ((!ans.empty() || r2 > r1) && c) {
        ans.push_back(2);
        c--;
    }

    for (int i = 0; i < d; i++) {
        ans.push_back(3);
        if (i != d-1 || c) {
            ans.push_back(2);
            c--;
        }
    }
    d = 0;

    while (b > 0 || c > 0) {
        if (c > b || (ans.size() > 1 && ans.back() == 1)) {
            ans.push_back(2);
            c--;
        } 
        else {
            ans.push_back(1);
            b--;
        }
    }

    //for (int x : ans) {pr(x); pr(" ");}
    //    ps();

    bool ok = a == 0 && b == 0 && c == 0 && d == 0;
    for (int i = 0; i+1 < ans.size(); i++) {
        if (abs(ans[i] - ans[i+1]) != 1) {
            ok = false;
            break;
        }
    }
     
    if (ok) {
        ps("YES");
        for (int x : ans) {pr(x); pr(" ");}
        ps();
    }
    else ps("NO");
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