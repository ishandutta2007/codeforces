#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int t=1;
struct Node{
	Node *index[30];
	Node *fail;
    Node *last;
	int word;
	int num;
	Node(){
		for(int i=0;i<30;i++)
		index[i]=NULL;
		fail=NULL;
		word=0;
		num=-1;
        last=NULL;
	}
}*root=new Node();
void add(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		if(!n->index[c[i]-'a'])
		n->index[c[i]-'a']=new Node();
		n=n->index[c[i]-'a'];
	}
	n->word=1;
	n->num=t++;
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
				if(p)
				n->index[i]->fail=p->index[i];
				else
				n->index[i]->fail=root;
			}
		}
	} 
}
vector<int> ans[100005];
void search(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		while(!n->index[c[i]-'a']&&n!=root){
			n=n->fail;
		}
		if(n->index[c[i]-'a'])
		n=n->index[c[i]-'a'];
		Node *p=n;
        Node *last=n;
		while(p){
			if(p->num!=-1)
			{
				ans[p->num].pb(i);
                if(last!=p){
                    last->last=p;
                    last=p;
                }
            }
            if(p->last)
            p=p->last;
            else
			p=p->fail;
		}
       // last->last=root;
	}
}
void del(Node *n=root){
	for(int i=0;i<30;i++)
	if(n->index[i])
	del(n->index[i]);
	free(n);
}
int main() {
    char c[100005];
    scanf("%s",c);
    root->num=0;
    int q;
    scanf("%d",&q);
    int need[100005],len[100005];
    for(int i=1;i<=q;i++){
        char c1[100005];
        scanf("%d %s",&need[i],c1);
        add(c1);
        len[i]=strlen(c1);
    }
 //   printf("?\n");
    ac();
    search(c);
    for(int i=1;i<=q;i++){
        if(need[i]>ans[i].size())
        printf("-1\n");
        else{
            int res=1e9;
            for(int j=need[i]-1;j<ans[i].size();j++){
                res=min(res,ans[i][j]-ans[i][j-need[i]+1]+len[i]);
            }
            printf("%d\n",res);
        }
    }
}