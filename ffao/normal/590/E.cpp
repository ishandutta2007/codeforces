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

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

// the maximum number of vertices
#define NN 1600

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int cap[NN][NN], deg[NN], adj[NN][NN];

// BFS stuff
int q[NN], prevpp[NN];

int dinic( int n, int s, int t )
{
    int flow = 0;

    // init the adjacency list adj[][] from cap[][]
    memset( deg, 0, sizeof( deg ) );
    for( int u = 0; u < n; u++ )
        for( int v = 0; v < n; v++ ) if( cap[u][v] || cap[v][u] )
            adj[u][deg[u]++] = v;

    while( true )
    {
        memset( prevpp, -1, sizeof( prevpp ) );
        int qf = 0, qb = 0;
        prevpp[q[qb++] = s] = -2;
        while( qb > qf && prevpp[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prevpp[v = adj[u][i]] == -1 && cap[u][v] )
                    prevpp[q[qb++] = v] = u;

        if( prevpp[t] == -1 ) break;

        for( int z = 0; z < n; z++ ) if( cap[z][t] && prevpp[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prevpp[v]; u >= 0; v = u, u = prevpp[v] )
                bot = min(bot, cap[u][v]);
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prevpp[v]; u >= 0; v = u, u = prevpp[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}


struct node{
	node *f, *p, *l, *d; //funcao de fail, primeiro filho, irmao
	int o; //marca se h uma string acabando
	char c; //letra
	void reset(){
		p=l=d=NULL;
		o=0;
	}

	node* son( char c ){ //retorna filho 'c'
		node* it;
		for( it=p ; it!=NULL ; it=it->l ){
			if( it->c==c ){
			return it;
			}
		}
		return NULL;
	}

	void add( char c, node* it ){ //adiciona filho
		it->c=c;
		it->l=p;
		p=it;
	}

};


struct word{
	int ini, len;
	int id;
};

const int MAXN = 800;
const int MAXD = 15000000;
node data[MAXD], *tree;
int d_cnt, n;
char s[MAXD+MAXN];
word v[MAXN];
queue<node*> qqq;
int g[MAXN][MAXN];

node* new_node(){
	data[d_cnt].reset();
	return &data[d_cnt++];
}

void free_all(){
	d_cnt=0;
}

bool comp( word a, word b ){
	return (a.len<b.len);
}


int seen[1600];

void dfs(int v) {
	//printf("dfs %d\n", v);
	if (seen[v]) return;
	seen[v] = 1;

	for (int i = 0; i < 2*n; i++) {
		//if (v==1)printf("cap %d %d %d\n", v, i, cap[v][i]);
		if (cap[v][i]) dfs(i); 
	}
}


//problema growing strings do spoj br
int main(){
	int i, j, k, resp;
	char c;
	node *p, *it, *jt, *kt;
	scanf("%d",&n);
	k=0;
	for( i=1 ; i<=n ; i++ ){ //le n strings
		scanf("%s",s+k);
		v[i].ini=k;
		v[i].len=strlen(s+k);
		v[i].id = i;
		k+=v[i].len+1;
	}

	free_all();
	tree=new_node();
	sort(v+1,v+1+n,comp);
	for( i=1 ; i<=n ; i++ ){ //monta arvore
		p=tree;
		for( j=v[i].ini ; (c=s[j])!='\0' ; j++ ){
			it=p->son(c);
			if( it==NULL ){
				p->add(c,it=new_node());
			}
			p=it;
		}
		p->o=i;
	}
	while( !qqq.empty() ){
		qqq.pop();
	}
	it=tree->p;
	for( it=tree->p ; it!=NULL ; it=it->l ){
	qqq.push(it);
	it->f=tree;
	}
	while( !qqq.empty() ){ //calcula os fail
	p=qqq.front();
	qqq.pop();
	for( it=p->p ; it!=NULL ; it=it->l ){
		qqq.push(it);
		for( jt=p->f ; (kt=jt->son(it->c))==NULL ; jt=jt->f ){
			if( jt==tree ){
				kt=tree;
				break;
			}
		}
		it->f=kt;
		if( kt->o!=0 ){
			it->d=kt;
		}
		else {
			it->d=kt->d;
		}
	}
	}
	resp=0;
	for( i=1 ; i<=n ; i++ ){ //problema growing strings
	p=tree;
	int cc = 0;
	for( j=v[i].ini ; (c=s[j])!='\0' ; j++ ){
		cc++;
		p=p->son(c);
		node *tmp = p;
		//printf("%d %d %d\n", i, cc, tmp->o);
		while (tmp != NULL && (tmp->o || tmp->d)) {
			if (tmp->o != 0) g[i][tmp->o] = 1;
			//printf("%d %d\n", i, tmp->o);
			tmp = tmp->d;
			if (tmp && tmp->o) g[i][tmp->o] = 1;
			break;
		}
	}
	p=p->f; //da fail pra nao achar propria string
	node *tmp = p;
	while (tmp != NULL && (tmp->o || tmp->d)) {
		if (tmp->o != 0) g[i][tmp->o] = 1;
		tmp = tmp->d;
		if (tmp && tmp->o) g[i][tmp->o] = 1;
		break;
	}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] |= g[i][k] && g[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (j != i) {
			cap[i-1][n + (j-1)] = g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cap[2*n][i] = 1;
		cap[n + i][2*n+1] = 1;
	}

	printf("%d\n", n - dinic(2*n + 2, 2*n, 2*n+1));

	for (int i = 0; i < n; i++) if (cap[2*n][i]) {
		dfs(i);
	}

	for (int i = 0; i < n; i++) if (seen[i] && !seen[n+i]) printf("%d ", v[i+1].id);
	printf("\n");

	return 0;
}