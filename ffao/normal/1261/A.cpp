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


typedef vector<int> vi;


int tttt;
char s[110000];
char t[110000];
int n, k;

void solve()
{
    for (re(tttt); tttt; tttt--) {
        re(n,k);
        scanf("%s", s);

        int op = 0;
        for (int i = 0; i < n; i++) {
            if (k > 1) {
                t[i++] = '(';
                t[i] = ')';
                k--;
            }
            else {
                int rem = n-i;
                if (rem == op) {
                    t[i] = ')';
                    op--;
                }
                else {
                    t[i] = '(';
                    op++;
                }
            }
        }

        vector< pair<int,int> > o;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
				for (int j = i+1; j < n; j++) if (s[j] == t[i]) {
					o.push_back({i, j});
					reverse(s+i, s+j+1);
					break;
				}
			}
        }

        printf("%d\n", (int)o.size());
        for (pair<int,int> x : o) printf("%d %d\n", x.first+1, x.second+1);
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
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