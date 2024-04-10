#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,mod=998244353;
struct mat{
	int v[2][2],n,m;
	mat(int a00,int a10,int a01,int a11) {
		v[0][0]=a00;
		v[1][0]=a10;
		v[0][1]=a01;
		v[1][1]=a11;
		n=m=2;
	}
	mat() {
		n=m;
		memset(v,0,sizeof(v));
	}
	mat operator*(const mat &a)const{
		mat b;
		b.n=n;
		b.m=a.m;
		for(int i=0;i<b.n;i++)
			for(int j=0;j<b.m;j++)
				for(int k=0;k<m;k++)
					b.v[i][j]=(b.v[i][j]+1ll*v[i][k]*a.v[k][j])%mod;
		return b;
	}
}pro[maxn<<2],f;
int a[maxn];
char s[maxn];
void build(int p,int l,int r) {
	if(l>r) {
		pro[1]={1,0,0,1};
		return;
	}
	if(l==r) {
		pro[p]=mat(0,1,(a[l+1]==1)*(10-a[l]-1),a[l+1]+1);
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pro[p]=pro[p<<1]*pro[p<<1|1];
}
void change(int p,int l,int r,int x,const mat &v) {
	if(l==r) {
		pro[p]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)change(p<<1,l,mid,x,v);
	else change(p<<1|1,mid+1,r,x,v);
	pro[p]=pro[p<<1]*pro[p<<1|1];
}
int main() {
	int n,m,x,v;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[n-i+1]=s[i]-'0';
	build(1,1,n-1);
	while(m--) {
		scanf("%d%d",&x,&v);
		a[x=n-x+1]=v;
		if(x>1)change(1,1,n-1,x-1,mat(0,1,(a[x]==1)*(10-a[x-1]-1),a[x]+1));
		if(x<n)change(1,1,n-1,x,mat(0,1,(a[x+1]==1)*(10-a[x]-1),a[x+1]+1));
		f=mat(1,0,a[1]+1,0)*pro[1];
		printf("%d\n",f.v[0][1]);
	}
	return 0;
}