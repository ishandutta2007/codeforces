#include<bits/stdc++.h>
using namespace std;
#define pf push_front
#define pb push_back
#define N 600005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define ll long long
int i,j,k,p,n,T,x,re[N],y,l,a[N],l0,l1,v[20][N],L[N],R[N];
long long ans;
char s[N],c;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void up(int k,int l,int r){
	if(s[v[re[r-l+1]][l]]=='?')a[k]=a[ls]+a[rs];
	else if(s[v[re[r-l+1]][l]]=='1')a[k]=a[rs];
	else a[k]=a[ls];
}
void build(int k,int l,int r){
	if(l==r)a[k]=1;
	else build(ls,l,mid),build(rs,mid+1,r),up(k,l,r);
}
void modify(int k,int l,int r,int L,int R){
	if(l==L&&r==R){up(k,l,r);return ;}
	if(R<=mid)modify(ls,l,mid,L,R);
	else modify(rs,mid+1,r,L,R);
	up(k,l,r);
}
int q,cnt;
int main(){
	scanf("%d%s%d",&k,s+1,&q);
	for(i=0;i<=k;++i)re[1<<i]=i;
	for(i=1;i<=k;++i){
		for(j=0;j<(1<<k);j+=(1<<i))v[i][j+1]=++cnt,L[cnt]=j+1,R[cnt]=j+(1<<i);
	}
	build(1,1,(1<<k));
	while(q--){
		cin>>p>>c;
		s[p]=c;
		modify(1,1,1<<k,L[p],R[p]);
		cout<<a[1]<<"\n";
	}
}