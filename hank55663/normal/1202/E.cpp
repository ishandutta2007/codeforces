#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
struct Node{
	Node *index[30];
	Node *fail;
    Node *last;
	//int word;
	//int num;
    int cnt;
  //  vector<pii> vis;
    int dep;
	Node(){
		for(int i=0;i<30;i++)
		index[i]=NULL;
		fail=NULL;
        last=NULL;
        cnt=0;
        dep=0;
       // vis.clear();
	}
}*root=new Node();
void add(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		if(!n->index[c[i]-'a']){
		    n->index[c[i]-'a']=new Node();
            n->index[c[i]-'a']->dep=n->dep+1;
        }
		n=n->index[c[i]-'a'];
	}
	n->cnt++;
}
void ac(){
	queue<Node*> q;
	q.push(root);
	root->fail=NULL;
	while(!q.empty()){
		Node *n=q.front();
		q.pop();
		for(int i=0;i<30;i++){
			if(n->index[i]){
				q.push(n->index[i]);
				Node* p=n->fail;
				while(p!=NULL&&!p->index[i])
				p=p->fail;
				if(p){
				    n->index[i]->fail=p->index[i];
                    n->index[i]->last=p->index[i]->last;
                    if(p->index[i]->cnt)
                        n->index[i]->last=p->index[i];
                }
				else{
				    n->index[i]->fail=root;
                }
            }
		}
	} 
}
int cnt1[200005],cnt2[200005];
void search(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		while(!n->index[c[i]-'a']&&n!=root){
			n=n->fail;
		}
		if(n->index[c[i]-'a'])
		n=n->index[c[i]-'a'];
        Node *p=n;
		while(p){
			//if(p->num!=-1)
			//{
			//	ans[p->num]++;
			//}
            cnt1[i]+=p->cnt;
            cnt2[i-p->dep]+=p->cnt;
			p=p->last;
		}
	}
}
void del(Node *n=root){
	for(int i=0;i<30;i++)
	if(n->index[i])
	del(n->index[i]);
	free(n);
}
int main(){
    char t[200005];
    scanf("%s",t);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        char c[200005];
        scanf("%s",c);
        add(c);
    }
    ac();
    search(t);
    LL ans=0;
    for(int i = 0;t[i]!=0;i++){
        ans+=(LL)cnt1[i]*cnt2[i];
    }
    printf("%lld\n",ans);
    return 0;
}
/* 
1 3 6 10 15
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */