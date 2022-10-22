#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

const int K=30;
int n,q;
#define Maxn 20005
#define Maxk 31
int a[Maxn],b[Maxn];
int anc[Maxn][15][Maxk];
int to[Maxk];
void trans(int *way,int D){
	per(i,K,0)
		per(j,K-i,0)way[i+j]=max(way[i+j],anc[way[i]][D][j]);
}

int merge(int x,int y){return b[x]>b[y]?x:y;}
int rmq[Maxn][15],LG[Maxn];
int calc(int l,int r){
	int t=LG[r-l+1];
	return merge(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

int kth;
int l,r;
bool Judge(int *way){
	rep(i,0,kth)
		if(way[i]+a[way[i]]+kth-i>=r)return true;
	return false;
}

int hh[Maxk],hhh[Maxk];

int main(){
	rd(n);rd(q);
	rep(i,2,n)LG[i]=LG[i>>1]+1;
	rep(i,1,n){
		rd(a[i]);
		b[i]=i+a[i];
	}
	rep(i,1,n)rmq[i][0]=i;
	rep(j,1,14)
		rep(i,1,n-(1<<j)+1)rmq[i][j]=merge(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
	rep(i,1,n)
		rep(j,0,K)anc[i][0][j]=calc(i,min(b[i]+j,n));
	per(i,n,1)
		rep(j,1,14){
			rep(k,0,K)anc[i][j][k]=anc[i][j-1][k];
			trans(anc[i][j],j-1);
		}
	rep(tt,1,q){
		rd(l);rd(r);rd(kth);
		if(l+a[l]+kth>=r){
			if(l==r)puts("0");
			else puts("1");
		}else{
			rep(i,0,K)hh[i]=l;
			int res=0;
			per(D,14,0){
				rep(i,0,K)hhh[i]=hh[i];
				trans(hhh,D);
				if(!Judge(hhh)){
					rep(i,0,K)hh[i]=hhh[i];
					res+=(1<<D);
				}
			}			
			printf("%d\n",res+2);
		}
	}
	return 0;
}