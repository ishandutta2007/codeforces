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


int n;
vector<int> a;

char ops[1100][1100];
int gr[1100][1100];
int on[1100][1100];

int valid[1100];
int cnt;

void solve()
{
    re(n); a.resize(n);
    re(a);

    for (int i = 0; i < n; i++) {
        int ones = a[i], zeros = n+1- ones;

        int taken = -100;
        for (int j = 0; j < n; j++) {
            if (gr[i][j] == gr[i][j+1]) {
                taken = j;
                on[i][gr[i][j]]++;
                ones--;
                break;
            }
        }

        for (int j = 0; j < n+1; j++) if (j != taken && taken+1 != j) {
            if (ones) {
                on[i][gr[i][j]]++;
                ones--;
            }
        }

        for (int j = 0; j < n+1; j++) {
            if (on[i][gr[i][j]]) {
                //printf("%d %d %d %d\n", i, j, gr[i][j], on[i][gr[i][j]]);
                ops[j][i] = '1';
                on[i][gr[i][j]]--;
            }
            else ops[j][i] = '0';
        }

        for (int j = 1; j < n+1; j++) { 
            if (gr[i][j] == gr[i][j-1] && ops[j][i] == ops[j-1][i]) {
                gr[i+1][j] = gr[i+1][j-1];
            }
            else gr[i+1][j] = gr[i+1][j-1] + 1;
        }
    }

    for (int i = 0; i < n+1; i++) {
        valid[i] = 0;
        for (int j = 0; j < n; j++) if (ops[i][j]=='1') valid[i] = 1;
        if (valid[i]) cnt++;
    }

    printf("%d\n", cnt);
    for (int i = 0; i < n+1; i++) if (valid[i]) {
        printf("%s\n", ops[i]);
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


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