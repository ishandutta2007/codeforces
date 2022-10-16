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


int n;

int cube[71][71][71];

void solve()
{
    re(n);
    int max_n = n*n*n;

	int c = 0;
	for (int i = n-1; i >= 0; i--) {
		if (i%2==0) {
			for (int y = 0; y < i; y++) cube[0][i][y] = ++c;
			for (int x = i; x >= 0; x--) cube[0][x][i] = ++c;
		}
		else {
			for (int x = 0; x <= i; x++) cube[0][x][i] = ++c;
			for (int y = i-1; y >= 0; y--) cube[0][i][y] = ++c;
		}
	}

    for (int i = 1; i < n; i++) {

		if (i % 2 == 1) {
			int cl = i, cx = i-1, cy = i-1;
			cube[cl][cx][cy] = ++c;

			while (cx > 0) {
				cube[cl][--cx][cy] = ++c;
			}

			for (int xx = 0; xx <= i-1; xx++) {
				if (xx % 2 == 0) for (int y = i-2; y >= 0; y--) cube[cl][xx][y] = ++c;
				else for (int y = 0; y <= i-2; y++) cube[cl][xx][y] = ++c;
			} 

			cx = i; cy = 0;

			for (int yy = 0; yy <= i; yy++) {
				if (yy % 2 == 0) for (int l = cl; l >= 1; l--) cube[l][cx][yy] = ++c;
				else for (int l = 1; l <= cl; l++) if (!(yy==i&&l!=0)) cube[l][cx][yy] = ++c;
			}

			cx = i; cy = i; 

			for (int ll = 1; ll <= i; ll++) {
				if (ll % 2 == 1) for (int x = i; x >= 0; x--) cube[ll][x][cy] = ++c;
				else for (int x = 0; x <= i; x++) cube[ll][x][cy] = ++c;
			}
		}

		else {
			int cl = i, cx = 0, cy = i-1;

			for (int xx = 0; xx <= i-1; xx++) {
				if (xx % 2 == 0) for (int y = i-1; y >= 0; y--) cube[cl][xx][y] = ++c;
				else for (int y = 0; y <= i-1; y++) cube[cl][xx][y] = ++c;
			} 

			cx = i;
			for (int ll = i; ll >= 1; ll--) {
				if (ll % 2 == i % 2) for (int yy = i-1; yy>=0;yy--) cube[ll][cx][yy] = ++c;
				else for (int yy = 0; yy <= i-1; yy++) cube[ll][cx][yy] = ++c;
			}
			cy = 0;

			cx = i, cy = i;
			for (int ll = 1; ll <= i; ll++) {
				if (ll % 2 == 1) for (int x = i; x >= 0; x--) cube[ll][x][cy] = ++c;
				else for (int x = 0; x <= i; x++) cube[ll][x][cy] = ++c;
			}
		}
    }

    for (int layer = 0; layer < n; layer++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                printf("%d ", cube[layer][x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


int main() {


    solve();
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