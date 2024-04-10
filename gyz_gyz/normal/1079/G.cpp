#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 100000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,a[N*12][16],b[N*12][16],lp[N][16],rp[N][16];
void bt1(int t,int x,int l,int r){
	if(l==r){
		if(l<0)a[x][t]=max(1-n,lp[l+n][t]-n);
		else if(l>=n)a[x][t]=min(n*2-2,lp[l-n][t]+n);
		else a[x][t]=lp[l][t];return;
	}int rr=l+(r-l)/2;
	bt1(t,x*2,l,rr);bt1(t,x*2+1,rr+1,r);
	a[x][t]=min(a[x*2][t],a[x*2+1][t]);
}
void bt2(int t,int x,int l,int r){
	if(l==r){
		if(l<0)b[x][t]=max(1-n,rp[l+n][t]-n);
		else if(l>=n)b[x][t]=min(n*2-2,rp[l-n][t]+n);
		else b[x][t]=rp[l][t];return;
	}int rr=l+(r-l)/2;
	bt2(t,x*2,l,rr);bt2(t,x*2+1,rr+1,r);
	b[x][t]=max(b[x*2][t],b[x*2+1][t]);
}
int q1(int t,int x,int l,int r,int L,int R){
	if(l<=L&&r>=R)return a[x][t];int rr=L+(R-L)/2;
	if(r<=rr)return q1(t,x*2,l,r,L,rr);
	if(l>rr)return q1(t,x*2+1,l,r,rr+1,R);
	return min(q1(t,x*2,l,r,L,rr),q1(t,x*2+1,l,r,rr+1,R));
}
int q2(int t,int x,int l,int r,int L,int R){
	if(l<=L&&r>=R)return b[x][t];int rr=L+(R-L)/2;
	if(r<=rr)return q2(t,x*2,l,r,L,rr);
	if(l>rr)return q2(t,x*2+1,l,r,rr+1,R);
	return max(q2(t,x*2,l,r,L,rr),q2(t,x*2+1,l,r,rr+1,R));
}
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("0");return 0;
	}
	rep(i,0,n-1){int x;
		scanf("%d",&x);
		lp[i][0]=max(i-x,i-n+1);
		rp[i][0]=min(i+x,i+n-1);
	}
	rep(j,0,15){
		bt1(j,1,1-n,n*2-2);
		bt2(j,1,1-n,n*2-2);
		if(j==15)break;
		rep(i,0,n-1){
			lp[i][j+1]=q1(j,1,lp[i][j],rp[i][j],1-n,n*2-2);
			rp[i][j+1]=q2(j,1,lp[i][j],rp[i][j],1-n,n*2-2);
		}
	}
	rep(i,0,n-1){int l=i,r=i,t=0;
		dep(j,15,0){
			int L=q1(j,1,l,r,1-n,n*2-2),R=q2(j,1,l,r,1-n,n*2-2);
			if(R-L<n-1)l=L,r=R,t+=1<<j;
		}
		printf("%d",t+1);if(i<n-1)printf(" ");
	}
}