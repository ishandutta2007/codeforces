#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e4+10;
const int mo=1e9+7;
const int inf=1e9;
int k,a[55][N],f[55][N],ml[55][N],mr[55][N],a1[N*4],a2[N*4];
void bd(int x,int l,int r,int y){
	if(l==r){
		a1[x]=f[y][l]-a[y+1][l-1];
		a2[x]=f[y][l]+a[y+1][l+k-1];return;
	}int m=(l+r)>>1;
	bd(x<<1,l,m,y);bd(x<<1|1,m+1,r,y);
	a1[x]=max(a1[x<<1],a1[x<<1|1]);
	a2[x]=max(a2[x<<1],a2[x<<1|1]);
}
int q1(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return a1[x];
	int m=(L+R)>>1;
	if(r<=m)return q1(x<<1,l,r,L,m);
	if(l>m)return q1(x<<1|1,l,r,m+1,R);
	return max(q1(x<<1,l,m,L,m),q1(x<<1|1,m+1,r,m+1,R));
}
int q2(int x,int l,int r,int L,int R){
	if(l==L&&r==R)return a2[x];
	int m=(L+R)>>1;
	if(r<=m)return q2(x<<1,l,r,L,m);
	if(l>m)return q2(x<<1|1,l,r,m+1,R);
	return max(q2(x<<1,l,m,L,m),q2(x<<1|1,m+1,r,m+1,R));
}
int main(){int n,m;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)rep(j,1,m){
		scanf("%d",&a[i][j]);
		a[i][j]+=a[i][j-1];
	}
	rep(i,1,m-k+1){
		f[1][i]=a[1][i+k-1]-a[1][i-1];
		if(n>1)ml[1][i]=max(ml[1][i-1],f[1][i]+a[2][i+k-1]-a[2][i-1]);
	}
	if(n>1){
		dep(i,m-k+1,1)mr[1][i]=max(mr[1][i+1],f[1][i]+a[2][i+k-1]-a[2][i-1]);
		bd(1,1,m-k+1,1);
	}
	rep(i,2,n){
		rep(j,1,m-k+1){
			int L=max(j-k+1,1),R=min(j+k-1,m-k+1);
			f[i][j]=max(ml[i-1][L-1],mr[i-1][R+1])+a[i][j+k-1]-a[i][j-1];
			if(L<j)f[i][j]=max(f[i][j],q1(1,L,j-1,1,m-k+1)+a[i][j+k-1]);
			f[i][j]=max(f[i][j],q2(1,j,R,1,m-k+1)-a[i][j-1]);
			if(i<n)ml[i][j]=max(ml[i][j-1],f[i][j]+a[i+1][j+k-1]-a[i+1][j-1]);
		}
		if(i<n){
			dep(j,m-k+1,1)mr[i][j]=max(mr[i][j+1],f[i][j]+a[i+1][j+k-1]-a[i+1][j-1]);
			bd(1,1,m-k+1,i);
		}
	}int ans=0;
	rep(i,1,m-k+1)ans=max(ans,f[n][i]);
	printf("%d\n",ans);
}