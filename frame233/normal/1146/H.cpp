#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=305;typedef long long ll;
struct vec{
	int x,y;
	inline vec operator += (const vec &o){x+=o.x,y+=o.y;return *this;}
	inline vec operator -= (const vec &o){x-=o.x,y-=o.y;return *this;}
	inline vec operator + (const vec &o)const{vec a(*this);return a+=o;}
	inline vec operator - (const vec &o)const{vec a(*this);return a-=o;}
	inline bool operator < (const vec &o)const{return x==o.x?y<o.y:x<o.x;}
	inline double ang()const{return atan2(y,x);}
}a[N];
int ord[N],b[N][N*2],dp[N][N][4],s[4];double c[N];
inline ll cross(const vec &a,const vec &b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
inline bool cmp(int x,int y){return c[x]<c[y];}
int main(){
	int n,K=5;read(n);
	for(int i=1;i<=n;++i)read(a[i].x,a[i].y);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int pos=0;for(int j=1;j<=n;++j)if(i!=j)c[j]=(a[j]-a[i]).ang(),b[i][++pos]=j;
		b[i][0]=i,std::sort(b[i]+1,b[i]+pos+1,cmp);
		for(int j=1;j<=pos;++j)b[i][j+pos]=b[i][j];
	}
	ll ans=0;
	for(int mn=1;mn<=n;++mn){
		memset(dp,0,sizeof(dp));int *t=b[mn];
		for(int j=0;j<n;++j)ord[b[mn][j]]=j;
		for(int i=1;i<n;++i)if(t[i]>mn){
			int x=t[i];dp[x][mn][0]=1;
			memset(s,0,sizeof(s));for(int j=n;j<=2*(n-1)-1;++j)if(ord[x]>ord[b[x][j]]&&b[x][j]>=mn)for(int c=0;c+1<=K-2;++c)s[c]+=dp[x][b[x][j]][c];
			for(int j=n-1,k=2*(n-1)-1;j>=1;--j){
				if(ord[x]>ord[b[x][j]]&&b[x][j]>=mn)for(int c=0;c+1<=K-2;++c)s[c]+=dp[x][b[x][j]][c];
				while(k>=j+n-1||cross(a[b[x][j]]-a[x],a[b[x][k]]-a[x])<0){
					if(ord[x]>ord[b[x][k]]&&b[x][k]>=mn)for(int c=0;c+1<=K-2;++c)s[c]-=dp[x][b[x][k]][c];
					--k;
				}
				if(ord[b[x][j]]>ord[x]&&b[x][j]>mn)for(int c=0;c+1<=K-2;++c)dp[b[x][j]][x][c+1]+=s[c];
			}
		}
		for(int i=1;i<n;++i)if(t[i]>mn)for(int j=0;j<i;++j)if(cross(a[mn]-a[t[i]],a[t[j]]-a[t[i]])>=0)ans+=dp[t[i]][t[j]][K-2];
	}
	printf("%lld\n",ans);
	return 0;
}