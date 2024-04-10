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


typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()


int n, q;
vi a;

vector< pair<pii, int> > queries;
int tree[210000];

vector< pii > elements;
int ans[210000];

void solve()
{
    re(n); a.resize(n);
    re(a);

    for (int i = 0; i < n; i++) {
        elements.push_back({-a[i], i+1});
    }
    sort(all(elements));

    re(q);
    for (int i = 0; i < q; i++) {
        int k, pos;
		re(k); re(pos);
        queries.push_back({{k,pos}, i});
    }

    sort(all(queries));
    int currq = 0;

    for (int i = 1; i <= n; i++) {
        for (int x = elements[i-1].second; x <= n; x += x&-x) tree[x]++;

        while (currq < q && queries[currq].first.first == i) {
            int pos = queries[currq].first.second;
            int idx = queries[currq].second;
            currq++;

            int st = 1, ed = n;
            while (st < ed) {
                int md = (st+ed)/2;

                int tot = 0;
                for (int x = md; x > 0; x -= x&-x) tot += tree[x];

                if (tot >= pos) ed = md;
                else st = md+1;
            }

            ans[idx] = a[st-1];
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
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