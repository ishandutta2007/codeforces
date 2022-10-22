#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e5+5;
struct Matrix{
	int a[5][5];
	Matrix operator * (const Matrix&other) const{
		Matrix res;memset(res.a,63,sizeof res.a);
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				for(int k=0;k<5;++k)
					res.a[i][j]=min(res.a[i][j],a[i][k]+other.a[k][j]);
		return res;
	}
	Matrix operator ^ (const Matrix&other) const{
		Matrix res;memset(res.a,63,sizeof res.a);
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				res.a[0][i]=min(res.a[0][i],a[0][j]+other.a[j][i]);
		return res;
	}
}I,ans,G[N],M[N<<2];
int n,q;char s[N];
inline void rd(int &x){
	x=0;char c=getchar();int f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
inline void build(int x,int l,int r){
	if(l==r)return void(M[x]=G[l]);
	int mid=l+r>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	M[x]=M[x<<1]*M[x<<1|1];
}
inline void query(int x,int l,int r,int L,int R){
	if(L<=l&&R>=r)return void(ans=ans^M[x]);
	int mid=l+r>>1;
	if(L<=mid)query(x<<1,l,mid,L,R);
	if(R>mid)query(x<<1|1,mid+1,r,L,R);
}
int main(){
	rd(n),rd(q);
	cin>>s+1;
	memset(I.a,63,sizeof I.a),I.a[0][0]=0;
	for(int i=1;i<=n;++i){
		memset(G[i].a,63,sizeof G[i].a);
		for(int j=0;j<5;++j)G[i].a[j][j]=0;
		if(s[i]=='2')G[i].a[0][0]=1,G[i].a[0][1]=0;
		if(s[i]=='0')G[i].a[1][1]=1,G[i].a[1][2]=0;
		if(s[i]=='1')G[i].a[2][2]=1,G[i].a[2][3]=0;
		if(s[i]=='7')G[i].a[3][3]=1,G[i].a[3][4]=0;
		if(s[i]=='6')G[i].a[3][3]=1,G[i].a[4][4]=1;
	}
	build(1,1,n);
	while(q--){
		int l,r;rd(l),rd(r);
		ans=I,query(1,1,n,l,r);
		printf("%d\n",ans.a[0][4]<=n?ans.a[0][4]:-1);
	}
	return 0;
}