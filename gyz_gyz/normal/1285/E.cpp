#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=6e5+10;
struct sg{
	int l,r,r0;
	friend bool operator<(const sg&a,const sg&b){return a.r<b.r;}
}s[N];
struct po{
	int x;bool l,r;
	friend po operator+(const po&a,const po&b){
		return{a.x+b.x-(a.r&&b.l),a.l,b.r};
	}
}a[N*4];
int v[N],f[N],l[N],sl[N],sr[N];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void bd(int x,int l,int r){
	if(l==r){
		if(v[l]==1)a[x]={1,1,1};else a[x]={0,0,0};return;
	}int m=(l+r)>>1;
	bd(x<<1,l,m);bd(x<<1|1,m+1,r);
	a[x]=a[x<<1]+a[x<<1|1];
}
po q(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return a[x];
	int m=(L+R)>>1;
	if(r<=m)return q(x<<1,l,r,L,m);
	if(l>m)return q(x<<1|1,l,r,m+1,R);
	return q(x<<1,l,m,L,m)+q(x<<1|1,m+1,r,m+1,R);
}
void sol(){int n;
	scanf("%d",&n);
	map<int,int>mp;
	rep(i,1,n){
		scanf("%d%d",&s[i].l,&s[i].r);
		s[i].l*=2;s[i].r*=2;++s[i].r;
		s[i].r0=s[i].r-1;
		mp[s[i].l]=mp[s[i].r]=mp[s[i].r0]=1;
	}int tot=0;
	for(auto&i:mp)i.sc=++tot;
	rep(i,1,n){
		s[i].l=mp[s[i].l];
		s[i].r=mp[s[i].r];
		s[i].r0=mp[s[i].r0];
	}
	sort(s+1,s+n+1);
	rep(i,1,n)f[i]=i,l[i]=s[i].l,sl[i]=sr[i]=1;
	stack<int>sk;
	rep(i,1,n){
		while(!sk.empty()){
			int x=sk.top();
			if(s[i].l<=s[x].r){
				f[x]=i;
				if(l[x]<l[i])l[i]=l[x],sl[i]=sl[x];
				else if(l[x]==l[i])sl[i]+=sl[x];
				if(s[x].r==s[i].r)sr[i]+=sr[x];
				sk.pop();
			}else break;
		}
		sk.push(i);
	}
	int nw=sk.size(),ans=-1;
	rep(i,1,tot)v[i]=0;
	rep(i,1,n)++v[s[i].l],--v[s[i].r];
	rep(i,1,tot)v[i]+=v[i-1];
	bd(1,1,tot);
	rep(i,1,n){
		int res=q(1,s[i].l,s[i].r0,1,tot).x;
		if(s[i].l==l[gf(i)]&&sl[gf(i)]==1)--res;
		if(s[i].r==s[gf(i)].r&&sr[gf(i)]==1)--res;
		ans=max(ans,res);
	}
	printf("%d\n",nw+ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}