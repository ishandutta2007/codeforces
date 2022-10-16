#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=1e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int size[xx],dfx[xx],dep[xx],f[xx][19],lg[xx],css;
void dfs(int x,int y)
{
	f[x][0]=y;size[x]=1;dep[x]=dep[y]+1,dfx[x]=++css;
	for(int i=1;i<=lg[xx-1];i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
int jump(int x,int y)
{
	for(int i=lg[y];i>=0;i--)if(y>>i&1)x=f[x][i];
	return x;
}
int root[xx];
struct nod{int sum,l,r;}w[xx*64];//insert 
#define e w
int cst;
void insert(int &k,int l,int r,int x,int y)
{
	if(x>n)return;
	cst++;e[cst]=e[k];k=cst;e[k].sum+=y;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)insert(e[k].l,l,mid,x,y);
	else insert(e[k].r,mid+1,r,x,y); 
}
int ask(int a,int b,int l,int r,int x,int y)
{
	if(x>y)return 0;
	if(x<=l&&r<=y)return e[b].sum-e[a].sum;
	int mid=l+r>>1;
	int ans=0;
	if(x<=mid)ans+=ask(e[a].l,e[b].l,l,mid,x,y);
	if(mid<y)ans+=ask(e[a].r,e[b].r,mid+1,r,x,y);
	return ans;
}
int get(int a,int b,int x,int y,int L)// 
{
	int A=ask(root[a],root[b],1,n,1,dfx[x]);
	int B=ask(root[a],root[b],1,n,1,dfx[y]);
	int C=ask(root[a],root[b],1,n,1,dfx[L]);
	int D=ask(root[a],root[b],1,n,1,dfx[f[L][0]]);
	return A+B-C-D;
}
int getone(int a,int b,int x)//x()10 
{
	int A=ask(root[a],root[b],1,n,1,dfx[x]);
	int B=ask(root[a],root[b],1,n,1,dfx[f[x][0]]);
	return A-B;
}
int ans,k,ia,ib;
bool check(int a,int b,int x,int y,int t,int L,int tt)//tt 
{
	int now=0;
	if(dep[x]-dep[L]+1>=t)now=jump(x,t-1);
	else now=jump(y,tt-t);
	int w=get(a,b,x,now,lca(x,now));//lca 
//	cout<<t<<" www "<<now<<" "<<t-w-ia-(now==y)*ib<<" "<<w<<" "<<L<<"\n";
	if(t-w-ia-(now==y)*ib>=k)return ans=now,1;
	return 0;
}
int main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	n=read();
	for(int i=1;i<=n;i++)
	{
		int o=read();
		if(!o)continue;
		add(o,i);
		add(i,o);
	}
	dfs(1,0);
	int m=read();
	for(int i=1;i<=m;i++)
	{
		root[i]=root[i-1];
		int op=read();
		if(op==1)
		{
			int x=read();
			insert(root[i],1,n,dfx[x],1);
			insert(root[i],1,n,dfx[x]+size[x],-1);
		}
		if(op==2)
		{
			int a,b,y;
			a=read();b=read();
			k=read();y=read();
			int L=lca(a,b);
			int ds=dep[a]+dep[b]-dep[L]-dep[f[L][0]];
			ia=!getone(y,i,a),ib=!getone(y,i,b);//1a 
//			cout<<ds-get(y,i,a,b,L)-ia-ib<<" ss "<<ia<<" "<<ib<<" "<<ds<<" "<<L<<" "<<check(y,i,a,b,ds,L,ds)<<"\n";
			if(ds-get(y,i,a,b,L)-ia-ib<k)
			{
				puts("-1");
				continue;
			}
			int l=1,r=ds;
			ans=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(check(y,i,a,b,mid,L,ds))r=mid-1;
				else l=mid+1;// 
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}