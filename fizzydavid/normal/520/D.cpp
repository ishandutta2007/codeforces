//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input1(x) x=getval()
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+9;
inline int getval()
{
	int __res=0;bool __neg=0;
	char __c;__c=getchar();
	while(__c==' '||__c=='\n')__c=getchar();
	while(__c!=' '&&__c!='\n')
	{
		if(__c=='-')__neg=1;
		else __res=__res*10+__c-'0';
		__c=getchar();
	}
	if(__neg)__res=-__res;
	return __res;
}
struct treap_node
{
	int v,fix;
	treap_node *l,*r;
	treap_node(){v=fix=0;l=r=NULL;}
};
treap_node *root;
void left_rotate(treap_node *&p)
{
	treap_node *t=p->r;
	p->r=t->l;
	t->l=p;
	p=t;
}
void right_rotate(treap_node *&p)
{
	treap_node *t=p->l;
	p->l=t->r;
	t->r=p;
	p=t;
}
void insert(treap_node *&p,int x)
{
	if(!p)
	{
		p=new treap_node;
		p->v=x;
		p->fix=rand();
	}
	else if(x==p->v)return;
	else if(x<p->v)
	{
		insert(p->l,x);
		if(p->l->fix<p->fix)right_rotate(p);
	}
	else
	{
		insert(p->r,x);
		if(p->r->fix<p->fix)left_rotate(p);
	}
}
void del(treap_node *&p,int x)
{
	if(p->v==x)
	{
		if(p->l==NULL||p->r==NULL)
		{
			treap_node *t=p;
			if(p->l!=NULL)p=p->l;else p=p->r;
			delete t;
		}
		else
		{
			if(p->l->fix<p->r->fix)
			{
				right_rotate(p);
				del(p->r,x);
			}
			else
			{
				left_rotate(p);
				del(p->l,x);
			}
		}
	}
	else if(x<p->v&&p->l!=NULL)del(p->l,x);
	else if(x>p->v&&p->r!=NULL)del(p->r,x);
}
treap_node* search(treap_node *p,int x)
{
	if(x==p->v)return p;
	else if(x<=p->v&&p->l!=NULL)search(p->l,x);
	else if(x>p->v&&p->r!=NULL)search(p->r,x);
}
treap_node* findmin(treap_node *p)
{
	if(p->l!=NULL)return findmin(p->l);
	else return p;
}
treap_node* findmax(treap_node *p)
{
	if(p->r!=NULL)findmax(p->r);
	else return p;
}
void tdebug(treap_node *p)
{
	cout<<p->v<<" "<<p->fix<<endl;
	if(p->l!=NULL){cout<<"left:"<<endl;tdebug(p->l);}else cout<<"NULL"<<endl;
	if(p->r!=NULL){cout<<"right:"<<endl;tdebug(p->r);}else cout<<"NULL"<<endl;
	cout<<p->v<<"end"<<endl;
}
int m;
bool used[100111],imp[100111];
int cntup[100111],cntdown[100111];
pair<int,int>p[100111];
map<pair<int,int>,int>pos;
void update1(int t)
{
	imp[t]=0;
	for(int i=-1;i<=1;i++)
	{
		int y=pos[MP(p[t].FF+i,p[t].SS+1)];
		if(y!=0&&!used[y]&&cntdown[y]==1)
		{
			imp[t]=1;
			del(root,t);
			return;
		}
	}
	if(!imp[t])insert(root,t);
}
void update2(int t)
{
	for(int i=-1;i<=1;i++)
	{
		int y=pos[MP(p[t].FF+i,p[t].SS-1)];
		if(y!=0&&!used[y])
		{
			imp[y]=1;
			del(root,y);
			break;
		}
	}
}
void remove(int t)
{
	used[t]=1;
	for(int i=-1;i<=1;i++)
	{
		int y=pos[MP(p[t].FF+i,p[t].SS-1)];
		if(y!=0&&!used[y])
		{
			cntup[y]--;
			update1(y);
		}
	}
	for(int i=-1;i<=1;i++)
	{
		int y=pos[MP(p[t].FF+i,p[t].SS+1)];
		if(y!=0&&!used[y])
		{
			cntdown[y]--;
			if(cntdown[y]==1)update2(y);
		}
	}
}
int main()
{
	input1(m);
	for(int i=1;i<=m;i++)
	{
		input2(p[i].FF,p[i].SS);
		pos[p[i]]=i;
	}
	for(int x=1;x<=m;x++)
	{
		for(int i=-1;i<=1;i++)
		{
			int y=pos[MP(p[x].FF+i,p[x].SS+1)];
			if(y!=0)cntup[x]++,cntdown[y]++;
		}
	}
	for(int x=1;x<=m;x++)
	{
//		cout<<cntup[x]<<" "<<cntdown[x]<<endl;
		for(int i=-1;i<=1;i++)
		{
			int y=pos[MP(p[x].FF+i,p[x].SS+1)];
			if(cntdown[y]==1)imp[x]=1;
		}
		if(!imp[x])insert(root,x);
	}
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int t;
		if(i&1)t=findmax(root)->v,del(root,t);else t=findmin(root)->v,del(root,t);
//		cout<<t<<endl;
		ans=(ans*m+t-1)%mod;
		remove(t);
	}
	printf("%I64d\n",ans);
	return 0;
}
/*
8
1 1
2 2
3 1
2 0
0 2
4 2
4 0
0 0
*/