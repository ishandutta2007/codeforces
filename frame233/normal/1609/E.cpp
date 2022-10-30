#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=100005,inf=0x3f3f3f3f;
struct mat{
	int a[3][3];
	mat(){memset(a,63,sizeof(a));}
	mat operator * (const mat &o)const{
		mat c;for(int i=0;i<3;++i)for(int k=0;k<3;++k)for(int j=0;j<3;++j)chmin(c.a[i][j],a[i][k]+o.a[k][j]);
		return c;
	}
}M[3];
char s[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
mat f[N<<2];
void build(int l,int r,int u){
	if(l==r)return f[u]=M[s[l]-'a'],void();
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
	f[u]=f[rs(u)]*f[ls(u)];
}
void Update(int pos,int l,int r,int u){
	if(l==r)return f[u]=M[s[l]-'a'],void();
	int mid=(l+r)>>1;pos<=mid?Update(pos,l,mid,ls(u)):Update(pos,mid+1,r,rs(u));
	f[u]=f[rs(u)]*f[ls(u)];
}
int main(){
	int n,q;read(n,q);scanf("%s",s+1);
	M[0].a[0][0]=1,M[0].a[1][0]=0,M[0].a[1][1]=0,M[0].a[2][2]=0;
	M[1].a[0][0]=0,M[1].a[1][1]=1,M[1].a[2][1]=0,M[1].a[2][2]=0;
	M[2].a[0][0]=0,M[2].a[1][1]=0,M[2].a[2][2]=1;
	build(1,n,1);
	int i;char c;
	while(q--){
		read(i);do{c=getchar();}while(!isalpha(c));
		s[i]=c,Update(i,1,n,1);
		printf("%d\n",std::min({f[1].a[0][0],f[1].a[1][0],f[1].a[2][0]}));
	}
	return 0;
}