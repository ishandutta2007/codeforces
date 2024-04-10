#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
const int mod=998244353;
int n,p[2][maxn],x[maxn],v[maxn],tl;
struct matrix {
	int a[2][2];
}M[maxn];
matrix mt(int a,int b,int c,int d){
	matrix m;m.a[0][0]=a;m.a[0][1]=b;m.a[1][0]=c;m.a[1][1]=d;
	return m;
}
matrix mul(matrix a,matrix b) {
	matrix c=mt(0,0,0,0);
	for(int k=0;k<2;++k)
	for(int i=0;i<2;++i)
	for(int j=0;j<2;++j)
		c.a[i][j]=(c.a[i][j]+(ll)a.a[i][k]*b.a[k][j]%mod)%mod;
	return c;
}

struct query {
	int s,v,p,i,j;
}q[maxn<<2];
int cmp(query a,query b){
	return (ll)a.s*b.v<(ll)b.s*a.v;
}

int get_speed(int i,int k1,int k2){
	if (k1==0&&k2==1)return -1;
	if (k1==1&&k2==0)return v[i]+v[i+1];
	if (k1==1&&k2==1)return v[i]-v[i+1];
	if (k1==0&&k2==0)return v[i+1]-v[i];
}

int qpow(int a,int b){
	if (b==0)return 1;
	ll d=qpow(a,b>>1);d=d*d%mod;
	if (b&1)d=d*a%mod;
	return d;
}

int inv(int x){return qpow(x,mod-2);}

struct segmentTree {
	matrix sum[maxn<<2];
	void update(int rt){
		sum[rt]=mul(sum[rt<<1],sum[rt<<1|1]);
	}
	void build(int l,int r,int rt){
		if (l==r){
			sum[rt]=M[l];
			return;
		}build(l,(l+r)>>1,rt<<1);
		build(((l+r)>>1)+1,r,rt<<1|1);
		update(rt);
	}
	void modify(int l,int r,int p,int rt){
		if (l==r){sum[rt]=M[l];return;}
		int mid=(l+r)>>1;
		if (p<=mid)modify(l,mid,p,rt<<1);
		else modify(mid+1,r,p,rt<<1|1);
		update(rt);
	}
}sgt;

int main(){
	ll ans=0;
	scanf("%d",&n);
	if (n==1){printf("0");return 0;}
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&x[i],&v[i],&p[1][i]);
		p[1][i]=(ll)p[1][i]*qpow(100,mod-2)%mod;
		p[0][i]=(1-p[1][i]+mod)%mod;
	}for(int i=1;i<n;++i){
		for(int j=0;j<2;++j)
		for(int k=0;k<2;++k){
			if (get_speed(i,j,k)<0)continue;
			q[++tl].s=x[i+1]-x[i];
			q[tl].v=get_speed(i,j,k);
			q[tl].p=i;
			q[tl].i=j;q[tl].j=k;
		}
	}
	for(int i=0;i<n;++i)
		M[i]=mt(p[0][i+1],p[1][i+1],p[0][i+1],p[1][i+1]);
	
	sgt.build(1,n-1,1);
	matrix m1=mul(M[0],sgt.sum[1]);
	std::sort(q+1,q+tl+1,cmp);
	for(int i=1;i<=tl;++i){
		matrix m1=M[q[i].p],m2=mt(0,0,0,0);
		m2.a[q[i].i][q[i].j]=p[q[i].j][q[i].p+1];
		M[q[i].p]=m2;
		sgt.modify(1,n-1,q[i].p,1);
		matrix m3=mul(M[0],sgt.sum[1]);
		int P=(m3.a[0][0]+m3.a[0][1])%mod;
		ans=((ans+(ll)q[i].s%mod*inv(q[i].v)%mod*P%mod)%mod+mod%mod);
		m1.a[q[i].i][q[i].j]=0;
		M[q[i].p]=m1;
		sgt.modify(1,n-1,q[i].p,1);
	}printf("%d",ans);
	return 0;
}