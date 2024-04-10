#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct Node{
	Node *index[30];
	Node *fail;
    Node *nword;
	int word;
	multiset<int> val;
	Node(){
		for(int i=0;i<30;i++)
		index[i]=NULL;
		fail=NULL;
		word=0;
		val.clear();
        val.insert(-1);
    }
}*root=new Node();
Node *nn[300005];
int val[300005];
Node* add(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		if(!n->index[c[i]-'a'])
		n->index[c[i]-'a']=new Node();
		n=n->index[c[i]-'a'];
	}
	n->word=1;
    n->val.insert(0);
    return n;
}
void ac(){
	queue<Node*> q;
	q.push(root);
	root->fail=NULL;
    root->nword=NULL;
	while(!q.empty()){
		Node *n=q.front();
		q.pop();
		for(int i=0;i<30;i++){
			if(n->index[i]){
				q.push(n->index[i]);
				Node* p=n->fail;
				while(p!=NULL&&!p->index[i])
				p=p->fail;
				if(p)
				n->index[i]->fail=p->index[i];
				else
				n->index[i]->fail=root;
                p=n->index[i]->fail;
                if(p->word)n->index[i]->nword=p;
                else n->index[i]->nword=p->nword;
			}
		}
	} 
}
int search(char c[]){
	Node *n=root;
    int res=-1;
	for(int i=0;c[i]!=0;i++){
		
		while(!n->index[c[i]-'a']&&n!=root){
			n=n->fail;
		}
		if(n->index[c[i]-'a'])
		n=n->index[c[i]-'a'];
		Node *p=n;
        while(p){
            res=max(res,*p->val.rbegin());
            p=p->nword;
        }
	}
    return res;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        char c[300005];
        scanf("%s",c);
        nn[i]=add(c);
    }
    ac();
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int i,x;
            scanf("%d %d",&i,&x);
            nn[i]->val.erase(nn[i]->val.find(val[i]));
            nn[i]->val.insert(x);
            val[i]=x;
        }
        else{
            char c[300005];
            scanf("%s",c);
            printf("%d\n",search(c));
        }
    }
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/