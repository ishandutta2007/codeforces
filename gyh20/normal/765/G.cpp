#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,P[2000002],Q[2000002],v[2000052],ans,f[42],g[42],fac[42],inv[42],lst[42];
char s[42];
long long pro,lmt;
struct node{
	long long x;int y;
	bool operator <(const node A)const{return x<A.x;}
};
const int MM=1145141;
struct Hash{
	int H[MM+1],cnt,nx[2000005],id[2000005];unsigned long long to[2000005];
	inline Hash(){memset(H,cnt=0,sizeof(H));}
	inline void clear(){memset(H,cnt=0,sizeof(H));}
	inline int& operator [] (const unsigned long long x){
		int p=x%MM;
		for(int i=H[p];i;i=nx[i])
		if(to[i]==x)return id[i];nx[++cnt]=H[p],to[H[p]=cnt]=x,id[cnt]=0;
		return id[cnt];
	}
}F,G;
double TT;
long long zt;
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
inline void Trans(re long long&x,re int y){
	if(m-y>=y)return;
	//printf("AAA%lld ",x);
	re long long zz=x>>m-y,ox;zz<=m-y;
	zz&=(1ll<<(y-(m-y)))-1;ox=x^(zz<<m-y);
	int oo=__builtin_popcountll(zz);
	zz=(1ll<<oo)-1,x=ox^(zz<<m-y);
	//printf("%lld\n",x);
}
inline void Trans1(re long long&x,re int y){
	if(m-y>=y)return;
//	int SS=clock();
	re long long zz=x>>m-y;zz<=m-y;
	zz&=(1ll<<(y-(m-y)))-1;
	re int pos=m-y;while(pos<y&&(!(zt&(1ll<<pos))||((x>>pos)&1)))++pos;
	while(zz){
		int i=__builtin_ctzll(zz)+m-y;
		if(pos<i){
			x^=1ll<<pos,x^=1ll<<i;
			while(pos<y&&(!(zt&(1ll<<pos))||((x>>pos)&1)))++pos;
		}
		zz^=1ll<<i-(m-y);
	}
//	TT-=clock()-SS;
}
int main(){
	//freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	scanf("%s",s),m=strlen(s);for(re int i=0;i<m;++i)s[i]-='0';
	n=read(),pro=1,lmt=1e9;
	for(re int i=1;i<=n;++i){
		P[i]=read(),Q[i]=read();
		for(re int j=1;j<=Q[i]&&pro<lmt;++j)pro=min(pro*P[i],lmt);
	}
	if(pro<=2000000){
		for(re int i=0;i<=pro+40;++i)v[i]=__gcd(i,(int)pro)==1;
		for(re int i=0;i<pro;++i){
			re bool ia=1;
			for(re int j=0;j<m;++j)ia&=v[i+j]==s[j];
			if(ia)++ans;
		}
		printf("%d\n",ans);
	}
	else if(n==1){
		re int num=0,ss=0;
		for(re int i=0;i<m;++i)num+=s[i]==0;
		if(num==0)ss=max(0,P[1]-m);
		else{
			for(re int i=P[1]-1;i>=max(0,P[1]-m);--i){
				re bool ia=1;
				for(re int j=0;j<m;++j)ia&=((i+j)%P[1]==0)!=s[j];
				if(ia)++ss;
			}
		}
		printf("%lld\n",1ll*ss*ksm(P[1],Q[1]-1)%M);
	}
	else{
		for(re int i=fac[0]=inv[0]=1;i<=m;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
		memset(f,0,sizeof(f)),f[0]=1,F[0]=1;
		re int num=0,ss=0;
		vector<int>tt;
		for(re int i=0;i<m;++i)zt=(zt<<1)|(s[i]^1),num+=s[i]==0;lst[0]=-1;
		for(re int i=1;i<m;++i){
			if((zt&(1ll<<i-1))>0)lst[i]=i-1;
			else lst[i]=lst[i-1];
		}
		for(re int i=1;i<=n;++i)
			if(P[i]>m){
				for(re int j=m;j;--j)f[j]=(1ll*f[j]*(P[i]-m+j)+f[j-1])%M;
				f[0]=1ll*f[0]*(P[i]-m)%M;
			}
			else tt.push_back(P[i]);
		sort(tt.begin(),tt.end());
		for(re int iii=0;iii<tt.size();++iii){int xx=tt[iii];
				G.clear();re int Sum=0;
				for(re int i=1;i<=F.cnt;++i){
					re long long tmp=F.to[i];re int v=F.id[i];add(v,Sum);Sum=0;
					re long long nv=0;
					for(re int k=0;k<m;k+=xx)nv|=1ll<<k;
					for(re int j=0;j<xx;++j){
						re long long cur=tmp|nv;nv<<=1;nv&=((1ll<<m)-1);
						if((cur&zt)!=cur)continue;
						if(num^m)Trans1(cur,tt[min((int)tt.size()-1,iii+1)]);
						else Trans(cur,tt[min((int)tt.size()-1,iii+1)]);
						add(G[cur],v);
					}
				}
				F=G;
		}
		for(re int i=0;i<=m;++i)
			for(re int j=1;j<=i;++j)
				f[i]=1ll*f[i]*j%M;
		for(re int j=1;j<=F.cnt;++j){
				re long long tmp=F.to[j];re int v=F.id[j],pop=__builtin_popcountll(tmp);
				if((tmp&zt)!=tmp)continue;
				for(re int i=0;i<=pop;++i)add(ss,1ll*v*C(pop,i)%M*f[num-pop+i]%M);
		}
		for(re int i=1;i<=n;++i)ss=1ll*ss*ksm(P[i],Q[i]-1)%M;
		printf("%d\n",ss);
		//printf("WWW%.3lf\n",1.0*TT/CLOCKS_PER_SEC);
	}
}