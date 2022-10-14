#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e2+1,INF=0x3f3f3f3f,M=7;
int n,m,ans;
int a[N][N],b[N][N];
int c[N][N][M],d[N][N][M];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)FOR(j,1,n)a[i][j]=b[i][j]=getint();
}
V mul(){
	static int C[N][N];
	FOR(i,1,n)FOR(j,1,n)C[i][j]=INF;
	FOR(i,1,n)FOR(j,1,n)FOR(k,1,n)
		C[i][j]=min(C[i][j],a[i][k]+b[k][j]);
	FOR(i,1,n)FOR(j,1,n)a[i][j]=C[i][j];
}
V ins(int x,int y,int z,int p){
	FOR(i,0,M-1)
		if(!d[x][y][i]){
			c[x][y][i]=z,d[x][y][i]=p;
			return;
		}
		else if(z<c[x][y][i]){
			ROF(j,5,i+1)
				c[x][y][j]=c[x][y][j-1],d[x][y][j]=d[x][y][j-1];
			c[x][y][i]=z,d[x][y][i]=p;
			return;
		}
}
V init(){
	FOR(i,1,n)a[i][i]=b[i][i]=INF;
//	FOR(i,1,m-1){
//		FOR(j,1,n)a[j][j]=INF;
//		mul();
//	}
//	ans=a[1][1];
	FOR(i,1,n)FOR(j,1,n)a[i][j]=b[i][j];
	FOR(i,1,n)FOR(j,1,n)FOR(k,1,n)if(k!=i&&k!=j)
		ins(i,j,a[i][k]+a[k][j],k);
//	cout<<ans<<'\n';
}
int t[N],tot,tag[N];
int tmp[N][N],bas[N][N];
I getmin(int x,int y){
	FOR(i,0,M-1)if(!tag[d[x][y][i]])
		return c[x][y][i];
	exit(1);
//	return INF;
}
V MUL(){
	static int C[N][N];
	FOR(i,1,tot)FOR(j,1,tot)C[i][j]=INF;
	FOR(i,1,tot)FOR(j,1,tot)FOR(k,1,tot)
		C[i][j]=min(C[i][j],tmp[i][k]+bas[k][j]);
	FOR(i,1,tot)FOR(j,1,tot)tmp[i][j]=C[i][j];
}
I solve(){
	FOR(i,1,tot)tag[t[i]]=1;
	FOR(i,1,tot)FOR(j,1,tot)
		tmp[i][j]=bas[i][j]=getmin(t[i],t[j]);
	FOR(i,1,m-1)MUL();
	FOR(i,1,tot)tag[t[i]]=0;
//	if(tmp[1][1]==0){
//		cout<<tot<<'\n';
//		FOR(i,1,tot)cout<<t[i]<<' ';
//		exit(0);
//	}
	return tmp[1][1];
}
V work(){
	m>>=1,t[1]=1,tag[0]=1,ans=0x7fffffff;
	if(m>=1&&n>m){
		tot=1,ans=solve();
	}
	if(m>=2&&n>m){
		tot=2;
		FOR(i,2,n)
			t[2]=i,ans=min(ans,solve());
	}
	if(m>=3&&n>m){
		tot=3;
		FOR(i,2,n)FOR(j,i+1,n)
			t[2]=i,t[3]=j,ans=min(ans,solve());
	}
	if(m>=4&&n>m){
		tot=4;
		FOR(i,2,n)FOR(j,i+1,n)FOR(k,j+1,n)
			t[2]=i,t[3]=j,t[4]=k,ans=min(ans,solve());
	}
	if(m>=5&&n>m){
		tot=5;
		FOR(i,2,n)FOR(j,i+1,n)FOR(k,j+1,n)FOR(p,k+1,n)
			t[2]=i,t[3]=j,t[4]=k,t[5]=p,ans=min(ans,solve());
		
	}
	cout<<ans<<'\n';
	
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}