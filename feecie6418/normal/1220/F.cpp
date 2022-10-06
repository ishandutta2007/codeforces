#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],w[500005],st[500005],top,c[500005][2],p[500005][20];
int d[500005],P[500005],L[500005],R[500005];
ll ans[500005];
struct Tg{
	ll x,y;
}tag[2000005];//w->max(w+x,y)
vector<int> q[500005];
//w->max(w+x.x,x.y)->max(max(w+x.x,x.y)+y.x,y.y)
Tg operator +(Tg x,Tg y){
	return {x.x+y.x,max(x.y+y.x,y.y)};
}
void Tag(int p,Tg z){
	tag[p]=tag[p]+z;
}
void Pushdown(int p){
	Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]={0,-(1ll<<60)};
}
void Apply(int p,int l,int r,int x,int y,Tg z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Apply(p*2,l,mid,x,y,z);
	if(mid<y)Apply(p*2+1,mid+1,r,x,y,z);
}
ll Get(int p,int l,int r,int x){
	if(l==r)return max(tag[p].x,tag[p].y);
	Pushdown(p);
	int mid=(l+r)/2;
	if(x>mid)return Get(p*2+1,mid+1,r,x);
	else return Get(p*2,l,mid,x);
}
void dfs(int x,int f){
	p[x][0]=f,d[x]=d[f]+1;
	for(int i=1;i<=18;i++)p[x][i]=p[p[x][i-1]][i-1];
	if(c[x][0])dfs(c[x][0],x);
	if(c[x][1])dfs(c[x][1],x);
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=18;i>=0;i--)if(d[p[x][i]]>=d[y])x=p[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(p[x][i]^p[y][i])x=p[x][i],y=p[y][i];
	return p[x][0];
}
void dfs2(int x,int l,int r){
	if(c[x][0])dfs2(c[x][0],l,x-1);
	ll T=0;
	if(c[x][0])T=Get(1,1,n,x-1);
	if(c[x][1]){
		dfs2(c[x][1],x+1,r);
		Apply(1,1,n,x+1,r,{w[x],T+w[x]});
	}
	Apply(1,1,n,x,x,{max(0ll,T)+w[x],-(1ll<<60)});
	for(int i:q[x])ans[i]=max(ans[i],Get(1,1,n,R[i])+w[P[i]]);
}
int main() {
	cin>>n,m=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]*=2,a[i+n]=a[i]-1;
	n*=2;
	for(int i=1;i<=4*n;i++)tag[i]={0,-(1ll<<60)};
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]>a[i])top--;
		int p=st[top];
		c[i][0]=c[p][1],c[p][1]=i,st[++top]=i;
	}
	dfs(st[1],0);
	for(int i=1;i<=n;i++)w[i]=1;
	for(int i=1;i<=m;i++){
		L[i]=i,R[i]=i+n/2-1,P[i]=LCA(L[i],R[i]),ans[i]=-1e18;
		if(P[i]!=R[i])q[c[P[i]][1]].push_back(i);
		else ans[i]=max(ans[i],(ll)w[R[i]]);
	}
	dfs2(st[1],1,n),top=0;
	for(int i=0;i<=n;i++)q[i].clear(),c[i][0]=c[i][1]=0,memset(p[i],0,sizeof(p[i])),d[i]=0;
	for(int i=1;i<=4*n;i++)tag[i]={0,-(1ll<<60)};
	reverse(a+1,a+n+1),reverse(w+1,w+n+1);
	for(int i=1;i<=n;i++){
		while(top&&a[st[top]]>a[i])top--;
		int p=st[top];
		c[i][0]=c[p][1],c[p][1]=i,st[++top]=i;
	}
	dfs(st[1],0);
	for(int i=1;i<=m;i++){
		L[i]=n-L[i]+1,R[i]=n-R[i]+1,swap(L[i],R[i]),P[i]=n-P[i]+1;
		if(P[i]!=R[i])q[c[P[i]][1]].push_back(i);
		else ans[i]=max(ans[i],(ll)w[R[i]]);
	}
	dfs2(st[1],1,n);
	int mx=1e9,mxp=0;
	for(int i=1;i<=m;i++){
		if(ans[i]<mx)mx=ans[i],mxp=i-1;
	}
	cout<<mx<<' '<<mxp;
}