#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
struct Thing{
	int l,r,v;
};
int n,q,a[200005],b[200005],st[200005],top,c[200005][2],f[200005][20],lg2[200005];
int L[200005],R[200005];
ll ans[1000005];
vector<int> d[200005];
vector<Thing> v1[200005],v2[200005];
pr tmp[200005],t2[200005];
vector<pr> q1[200005],q2[200005];
int Max(int x,int y){
	return a[x]>a[y]?x:y;
}
int Get(int l,int r){
	int k=lg2[r-l+1];
	return Max(f[l][k],f[r-(1<<k)+1][k]);
}
struct Segtree{

ll c1[200005],c2[200005];
void U(ll c[],int x,ll y){
	while(x<=n)c[x]+=y,x+=x&-x;
}
ll Q(ll c[],int x){
	ll r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
void Make(int l,int r,int x){
	//cout<<"M:"<<l<<' '<<r<<' '<<x<<'\n';
	U(c1,l,x);
	U(c1,r+1,-x);
	U(c2,l,1ll*x*(1-l));
	U(c2,r+1,-1ll*x*(1-r-1));
}
ll Sum(int l,int r){
	//cout<<"S:"<<l<<' '<<r<<' '<<(Q(c2,r)+r*Q(c1,r))-(Q(c2,l-1)+(l-1)*Q(c1,l-1))<<'\n';
	return (Q(c2,r)+r*Q(c1,r))-(Q(c2,l-1)+(l-1)*Q(c1,l-1));
}

}u1,u2;
void dfs(int x){
	if(c[x][0])dfs(c[x][0]);
	if(c[x][1])dfs(c[x][1]);
	//cout<<"X:"<<x<<'\n';
	for(auto i:v1[x])u2.Make(i.l,i.r,max(R[x]-i.v+1,0));
	for(auto i:v2[x])u1.Make(i.l,i.r,max(i.v-L[x]+1,0));
	for(auto i:q1[x])ans[i.second]+=u1.Sum(L[x],i.first);
	for(auto i:q2[x])ans[i.second]+=u2.Sum(i.first,R[x]);
	//cout<<ans[1]<<' '<<u1.Sum(2,2)<<'\n';
}
void dfs0(int x,int l,int r){
	L[x]=l,R[x]=r;
	if(c[x][0])dfs0(c[x][0],l,x-1);
	if(c[x][1])dfs0(c[x][1],x+1,r);
}
int main(){
	scanf("%d%d",&n,&q),lg2[0]=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i)d[j].push_back(i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),b[a[i]]=i;
		while(top&&a[st[top]]<a[i])top--;
		int p=st[top];
		c[i][0]=c[p][1],c[p][1]=i,st[++top]=i;
		lg2[i]=lg2[i>>1]+1;
		f[i][0]=i;
	}
	dfs0(st[1],1,n);
	for(int i=1;i<=17;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f[j][i]=Max(f[j][i-1],f[j+(1<<i-1)][i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		int x=b[i],ts=0;
		for(int j:d[i]){
			if(j*j==i)continue;
			int p=b[j],q=b[i/j];
			if(p>q)swap(p,q);
			if(p<L[x]||q>R[x])continue;
			p=min(p,x),q=max(q,x);
			tmp[++ts]=pr(q,p);
		}
		sort(tmp+1,tmp+ts+1);
		int mn=0,ss=0;
		for(int j=1;j<=ts;j++)if(tmp[j].second>mn)mn=tmp[j].second,t2[++ss]=tmp[j];
		
		if(1<=ss&&t2[ss].second<x)v1[x].push_back({t2[ss].second+1,x,n+1});
		for(int j=1;j<=ss;j++){
			if(j>1)v1[x].push_back({t2[j-1].second+1,t2[j].second,t2[j].first});
			else v1[x].push_back({L[x],t2[j].second,t2[j].first});
		}
		
		if(1<=ss&&t2[1].first>x)v2[x].push_back({x,t2[1].first-1,0});
		for(int j=1;j<=ss;j++){
			if(j<ss)v2[x].push_back({t2[j].first,t2[j+1].first-1,t2[j].second});
			else v2[x].push_back({t2[j].first,R[x],t2[j].second});
		}
		//cout<<"I:"<<i<<'\n';
		//for(auto i:v1[x]){
		//	cout<<i.l<<' '<<i.r<<' '<<i.v<<'\n';
		//}
		//cout<<i<<' '<<v1[x].size()<<' '<<v2[x].size()<<' '<<ss<<'\n';
	}
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		int x=Get(l,r);
		for(auto j:v2[x]){
			ans[i]+=1ll*max(min(r,j.r)-j.l+1,0)*max(j.v-max(l,L[x])+1,0);
			//cout<<j.l<<' '<<j.r<<' '<<j.v<<'\n';
		}
		if(l<x)q2[Get(l,x-1)].push_back({l,i});
		if(r>x)q1[Get(x+1,r)].push_back({r,i});
		//cout<<i<<' '<<ans[i]<<'\n';
	}
	dfs(st[1]);
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}