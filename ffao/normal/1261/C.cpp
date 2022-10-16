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


int rows, cols;
char s[1100000];

void solve()
{
    re(rows,cols);
    
    vector<string> board;
    for (int i = 0; i < rows; i++) {
        scanf("%s", s);
        board.push_back(s);
    }

    vector< vector<int> > sq(rows+10, vector<int>(cols+10,0));
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (board[i-1][j-1] == 'X') sq[i][j] = min(sq[i-1][j-1], min(sq[i-1][j], sq[i][j-1])) + 1;
            else sq[i][j] = 0;
            //printf("%d ", sq[i][j]);
        }
        //printf("\n");
    }

    int st = 0, ed = min(rows,cols);
    while (st < ed) {
        int bs = (st+ed+1)/2;
        int md = 2*bs+1;

        //printf("st = %d ed = %d bs = %d md = %d\n", st,ed,bs,md);
        vector< vector<int> > cover(rows+10, vector<int>(cols+10,0));
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (sq[i][j] >= md) {
                    cover[i][j]++;
                    cover[i-md][j]--;
                    cover[i][j-md]--;
                    cover[i-md][j-md]++;
                }
            }
        }

        for (int i = rows; i >= 1; i--) {
            for (int j = cols; j >= 1; j--) {
                cover[i][j] += cover[i+1][j] + cover[i][j+1] - cover[i+1][j+1];
            }
        }

        bool ok = true;
        for (int i = 1; i <= rows && ok; i++) {
            for (int j = 1; j <= cols; j++) if (board[i-1][j-1] == 'X' && cover[i][j] <= 0) {
                ok = false;
                break;
            }
        }

        if (ok) st = bs;
        else ed = bs-1;
    }

    printf("%d\n", st);

    int md = 2*st+1;
    vector<string> outboard = board;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i+st <= rows && j+st<=cols && sq[i+st][j+st] >= md) printf("X");
            else printf(".");
        }
        printf("\n");
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