#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int mod=998244353;
typedef long long ll;
int n,a[N],b[N],p[N][2],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int inv100=qpow(100,mod-2);
struct Matrix{
	int g[2][2];
	Matrix(){memset(g,0,sizeof(g));}
public:
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=0;i<=1;++i){
			for(int j=0;j<=1;++j){
				c.g[i][j]=(1LL*a.g[i][0]*b.g[0][j]+1LL*a.g[i][1]*b.g[1][j])%mod;	
			}
		}
		return c;
	}
	int get_val(){
		return (g[0][0]+g[0][1])%mod;	
	}
};
class Segment_Tree{
	struct node{
		Matrix p;
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].p=t[ls].p*t[rs].p;
	}
public:
	void build(int u,int L,int R){
		if(L==R){
			t[u].p.g[0][0]=t[u].p.g[1][0]=p[L][0];
			t[u].p.g[0][1]=t[u].p.g[1][1]=p[L][1];
			return;	
		}	
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void Change(int u,int L,int R,int p,int x,int y){
		if(L==R){
			t[u].p.g[x][y]=0;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p,x,y):Change(rs,mid+1,R,p,x,y);
		update(u);	
	}
	int get_ans(){
		return t[1].p.get_val();
	}
}T;
int m;
struct Data{
	int p,x,y,L,S;
}c[N<<1];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>p[i][1];
		p[i][1]=1LL*inv100*p[i][1]%mod;
		p[i][0]=mod+1-p[i][1];
	}
	T.build(1,1,n);
	for(int i=2;i<=n;++i){
		c[++m]=(Data){i,1,0,a[i]-a[i-1],b[i]+b[i-1]};
		if(b[i-1]<b[i]){
			c[++m]=(Data){i,0,0,a[i]-a[i-1],b[i]-b[i-1]};
		}
		else if(b[i-1]>b[i]){
			c[++m]=(Data){i,1,1,a[i]-a[i-1],b[i-1]-b[i]};	
		}
	}
	sort(c+1,c+m+1,[&](Data a,Data b){return 1LL*a.L*b.S<1LL*a.S*b.L;});
	int las=1;
	for(int i=1;i<=m;++i){
		T.Change(1,1,n,c[i].p,c[i].x,c[i].y);
		int now=T.get_ans();
		ans=(ans+1LL*c[i].L*qpow(c[i].S,mod-2)%mod*(las-now+mod))%mod;
		las=now;
	}
	cout<<ans<<'\n';
	return 0;
}