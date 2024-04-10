#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[500005],f[500005],c1[500005],c2[500005],c3[500005];
ll s[500005],b[500005];
void U1(int x,int y){
	while(x<=n+1)c1[x]=max(c1[x],y),x+=x&-x;
}
void U2(int x,int y){
	x=n+2-x;
	while(x<=n+1)c2[x]=max(c2[x],y),x+=x&-x;
}
void U3(int x,int y){
	c3[x]=max(c3[x],y);
}
int Q1(int x){
	int r=-1e9;
	while(x)r=max(r,c1[x]),x-=x&-x;
	return r;
}
int Q2(int x){
	x=n+2-x;
	int r=-1e9;
	while(x)r=max(r,c2[x]),x-=x&-x;
	return r;
}
int Q3(int x){
	return c3[x];
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	for(int i=0;i<=n;i++)b[i+1]=s[i];
	for(int i=0;i<=n+1;i++)c1[i]=c2[i]=c3[i]=-1e9;
	sort(b+1,b+n+2),f[0]=0;
	int id=lower_bound(b+1,b+n+2,s[0])-b;
	U1(id,0);
	U2(id,0);
	U3(id,0);
	for(int i=1;i<=n;i++){
		int id=lower_bound(b+1,b+n+2,s[i])-b;
		f[i]=-1e9;
		f[i]=max(f[i],Q1(id-1)+i);
		f[i]=max(f[i],Q2(id+1)-i);
		f[i]=max(f[i],Q3(id));
		U1(id,f[i]-i);
		U2(id,f[i]+i);
		U3(id,f[i]);
	}
	cout<<f[n]<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}