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
struct Node{
	Node *index[30];
	Node *fail;
    Node *past;
	vector<pair<pii,int> > que;
    int now;
    int ok;
	Node(){
		for(int i=0;i<30;i++)
		index[i]=NULL;
		fail=NULL;
        past=NULL;
        now=0;
        ok=1;
    }
}*root=new Node();
void add(char c[],int num,int q){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		if(!n->index[c[i]-'a']){
		    n->index[c[i]-'a']=new Node();
        }
		n=n->index[c[i]-'a'];
	}
	n->que.pb(mp(mp(num,q),0));
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
                    if(p->index[i]->que.size())
                        n->index[i]->past=p->index[i];
                    else
                        n->index[i]->past=p->index[i]->past;
                }
                else{
				    n->index[i]->fail=root;
                    n->index[i]->past=NULL;
                }
            }
		}
	} 
}
vector<pair<int,char> > v[400005];
int ti=0;
int in[400005];
int out[400005];
void dfs(int x){
    in[x]=++ti;
    for(auto it:v[x]){
        dfs(it.x);
    }
    out[x]=ti;
}
void search(int x,Node *n){
    //in[x]=++ti;
    Node *p=n;
	while(p){
        while(p->now!=p->que.size()&&in[p->que[p->now].x.x]<in[x])p->now++;
        if(p->now!=p->que.size())
        p->que[p->now].y++;
        p=p->past;
    }
    for(auto it:v[x]){
        Node *Next=n;
        if(n->index[it.y-'a']){
            search(it.x,n->index[it.y-'a']);
        }
        else{
            while(!Next->index[it.y-'a']&&Next!=root)Next=Next->fail;
            if(Next->index[it.y-'a'])Next=Next->index[it.y-'a'];
            n->index[it.y-'a']=Next;
            search(it.x,Next);
        }
    }
	p=n;
	while(p){
        while(p->now!=p->que.size()&&in[p->que[p->now].x.x]<=out[x])p->now++;
        if(p->now!=p->que.size())
        p->que[p->now].y--;
        p=p->past;
    }
}
int ans[400005];
bool cmp(const pair<pii,int> &a,const pair<pii,int> &b){
    return in[a.x.x]<in[b.x.x];
}
void go(Node *n=root){
    if(n){
        for(int i = 0;i<30;i++){
            go(n->index[i]);
        }
        sort(n->que.begin(),n->que.end(),cmp);
    }
}
void gogo(Node *n=root){
    if(n&&n->ok){
        n->ok=0;
        for(int i = 0;i<30;i++){
            gogo(n->index[i]);
        }
        int sum=0;
        for(auto it:n->que){
            sum+=it.y;
            ans[it.x.y]=sum;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            char c;
            scanf(" %c",&c);
            v[0].pb(mp(i,c));
        }
        else{
            int x;
            char c;
            scanf("%d %c",&x,&c);
            v[x].pb(mp(i,c));
        }
    }
    dfs(0);
    int m;
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        int x;
        char c[400005];
        scanf("%d %s",&x,c);
        add(c,x,i);
    }
    ac();
    go();
    //printf("!\n");
    search(0,root);
    //printf("?\n");
    gogo();
    for(int i = 0;i<m;i++)
        printf("%d\n",ans[i]);
}