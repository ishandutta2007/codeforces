#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define cl(x) memset(x,0,l<<2)
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,A,B) for(rnt i(A);i<=B;i++)
#define ROF(i,A,B) for(rnt i(A);i>=B;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
const int N=2e3+1;
I getint() {
	rnt _s=0;
	re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
int T,n,m;
int a[N][15],b[N][15],f[N][1<<12];
int ans[N],tim;
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)FOR(j,1,m)a[j][i]=getint();
//	if(tim==36&&ans[1]==15&&ans[2]==23&&ans[3]==39&&ans[4]==4&&ans[19]==30){
//		cout<<n<<' '<<m<<'\n';
//		FOR(i,1,n)FOR(j,1,m)cout<<a[j][i]<<" \n"[j==m];
//		exit(0);
//	}
}
int id[N],jb[N];
bool cmp(const int&x,const int&y){return jb[x]>jb[y];}
V init(){
	FOR(i,1,m){
		jb[i]=0,id[i]=i;
		FOR(j,1,n)jb[i]=max(jb[i],a[i][j]);
	}
	memset(f,0,sizeof(f)),sort(id+1,id+1+m,cmp),m=min(m,n);
	FOR(i,1,m)swap(b[i],a[id[i]]);
//	FOR(i,1,m)swap(a[i],a[id[i]]);
}
int tmp[1<<12],can[1<<12];
int use[1<<12][1<<12|1];
V work(){
	rnt s=1<<n,now=0;
	s--,memset(can,0,sizeof(can));
	FOR(i,0,s)FOR(j,0,s)if((i|j)==i)use[i][++can[i]]=j;
	FOR(i,1,m){
		memset(tmp,0,sizeof(tmp));
		FOR(j,1,n){
			b[i][n+1]=b[i][1];
			FOR(k,1,n)b[i][k]=b[i][k+1];
			FOR(k,0,s){
				FOR(p,1,n)if(k&(1<<p-1))now+=b[i][p];
				tmp[k]=max(tmp[k],now),now=0;
			}
		}
		FOR(j,0,s)FOR(k,1,can[j])
			f[i][j]=max(f[i][j],f[i-1][j^use[j][k]]+tmp[use[j][k]]);
	}
//	ans[++tim]=f[m][s];
	cout<<f[m][s]<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	T=getint();
	FOR(i,1,T)input(),init(),work();
//	FOR(i,1,T)cout<<ans[i]<<'\n';
	return 0;
}