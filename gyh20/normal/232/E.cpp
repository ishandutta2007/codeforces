#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,m,Q,a[N][N],ans[600005];
bitset<N>f[N][N],g[N][N];
char s[N];
struct query {
	int a,b,c,d,id;
	query(int A=0,int B=0,int C=0,int D=0,int Id=0) {
		a=A,b=B,c=C,d=D,id=Id;
	}
};
vector<query>q[N<<2];
const int Mxdt=100000;
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj) {
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read() {
	int res=0,bj=0;
	char ch=gc();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return bj?-res:res;
}
void print(int x) {
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch) {
	if(x<0)pc('-',false),x=-x;
	print(x),pc(ch,false);
}
void Divide(int p,int l,int r) {
	int mid=(l+r)>>1;
	for(int i=1; i<=n; ++i)for(int j=l; j<=mid; ++j)f[i][j]=0;
	for(int i=1; i<=n; ++i)for(int j=mid; j<=r; ++j)g[i][j]=0;
	for(int i=n; i>=1; --i)if(!a[i][mid])f[i][mid][i]=1,f[i][mid]|=f[i+1][mid];
	for(int i=1; i<=n; ++i)if(!a[i][mid])g[i][mid][i]=1,g[i][mid]|=g[i-1][mid];
	for(int i=n; i>=1; --i)for(int j=mid-1; j>=l; --j)if(!a[i][j])f[i][j]=f[i+1][j]|f[i][j+1];
	for(int i=1; i<=n; ++i)for(int j=mid+1; j<=r; ++j)if(!a[i][j])g[i][j]=g[i-1][j]|g[i][j-1];
	for(auto y:q[p]) {
		if(y.b<=mid&&mid<=y.d)ans[y.id]|=((f[y.a][y.b]&g[y.c][y.d]).count()>0);
		else if(y.d<mid)q[p<<1].push_back(y);
		else q[p<<1|1].push_back(y);
	}
	if(l<mid)Divide(p<<1,l,mid-1);
	if(mid<r)Divide(p<<1|1,mid+1,r);
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,j; i<=n; ++i)for(scanf("%s",s+(j=1)); j<=m; ++j)a[i][j]=s[j]=='#';
	Q=read();
	for(int i=1,a,b,c,d; i<=Q; ++i)a=read(),b=read(),c=read(),d=read(),q[1].push_back(query(a,b,c,d,i));
	Divide(1,1,m);
	for(int i=1; i<=Q; ++i) {
		if(ans[i])pc('Y',0),pc('e',0),pc('s',0),pc('\n',0);
		else pc('N',0),pc('o',0),pc('\n',0);
	}
	return pc('h',true);
}