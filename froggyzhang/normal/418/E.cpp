#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m1,m2,m,a[N],pos[N];
int b[N<<1],ZZ;
int ans[N];
struct Query{
	int x,y,z,id;
}c[N],q[N];
int ct1[N<<1],ct2[N<<1];
inline void Add(int x,int d){
	if(d==1)++ct1[x],++ct2[ct1[x]];
	else --ct2[ct1[x]],--ct1[x];
}
inline int Ask(int x,int opt){
	if(opt==1){
		return b[x];
	}
	else if(opt&1){
		return ct2[ct1[x]];
	}
	else{
		return ct1[x];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[++ZZ]=a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==1){
			++m1;
			c[m1]={y,x,m1,m1};
			b[++ZZ]=x;
		}
		else{
			++m2;
			q[m2]={y,m1,x,m2};
		}
	}
	sort(b+1,b+ZZ+1);
	ZZ=unique(b+1,b+ZZ+1)-b-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+ZZ+1,a[i])-b;
	}
	for(int i=1;i<=m1;++i){
		c[i].y=lower_bound(b+1,b+ZZ+1,c[i].y)-b;
	}
	int len=max(1,n/max(1,(int)sqrt(m2)));
	for(int i=1;i<=n;++i){
		pos[i]=(i-1)/len+1;
	}
	sort(q+1,q+m2+1,[&](Query a,Query b){
		return pos[a.x]==pos[b.x]?(pos[a.x]&1?a.y<b.y:a.y>b.y):a.x<b.x;
	});
	for(int i=1,t=0,p=0;i<=m2;++i){
		while(t<q[i].y){
			++t;
			if(c[t].x<=p)Add(a[c[t].x],-1);
			swap(a[c[t].x],c[t].y);
			if(c[t].x<=p)Add(a[c[t].x],1);
		}
		while(t>q[i].y){
			if(c[t].x<=p)Add(a[c[t].x],-1);
			swap(a[c[t].x],c[t].y);
			if(c[t].x<=p)Add(a[c[t].x],1);
			--t;
		}
		while(p<q[i].x){
			++p;
			Add(a[p],1);
		}
		while(p>q[i].x){
			Add(a[p],-1);
			--p;
		}
		ans[q[i].id]=Ask(a[q[i].x],q[i].z);
	}
	for(int i=1;i<=m2;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}