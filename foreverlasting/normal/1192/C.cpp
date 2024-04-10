//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int P=998244353;
inline void upd(R int &x,R int y){(x+=y)>=P?x-=P:0;}
inline int inc(R int x,R int y){return x+y>=P?x+y-P:x+y;}
inline int dec(R int x,R int y){return x-y<0?x-y+P:x-y;}
inline int mul(R int x,R int y){return 1ll*x*y-1ll*x*y/P*P;}
int ksm(R int x,R int y){
	R int res=1;
	for(;y;y>>=1,x=mul(x,x))(y&1)?res=mul(res,x):0;
	return res;
}
const int N=65;
char s[15];int id[233],cnt[N][N][N][15],c[N][N][15],fac[15],dv[35],n,res;
inline void init(){
	R int tp=0;
	fp(i,'a','z')id[i]=++tp;
	fp(i,'A','Z')id[i]=++tp;
	fp(i,'0','9')id[i]=++tp;
	fac[0]=fac[1]=1,fac[2]=2,fac[3]=6,fac[4]=24;
	fp(i,1,24)dv[i]=24/i;
}
inline void swap(R int &x,R int &y){R int t=x;x=y,y=t;}
const int M=2e6+5;
int ch[M][65],vis[M],nd,len,fl;
bool ck(){
	R int p=0;
	fp(i,1,len){
		if(!ch[p][id[s[i]]])return false;
		p=ch[p][id[s[i]]];
	}
	return vis[p];
}
void ip(){
	R int p=0;
	fp(i,1,len){
		if(!ch[p][id[s[i]]])ch[p][id[s[i]]]=++nd;
		p=ch[p][id[s[i]]];
	}
	vis[p]=1;
	reverse(s+1,s+1+len),p=0;
	fp(i,1,len){
		if(!ch[p][id[s[i]]])ch[p][id[s[i]]]=++nd;
		p=ch[p][id[s[i]]];
	}
	vis[p]=1;
}
inline void ins(char *s){
	len=strlen(s+1),fl=1;
	if(ck())return;
	fp(i,1,len>>1)if(s[i]!=s[len-i+1]){fl=0;break;}
	++c[id[s[1]]][id[s[len]]][len];
	if(!fl)++c[id[s[len]]][id[s[1]]][len];
	ip();
}
inline int calc(R int a,R int b,R int c,R int d){
	static int st[15];
	st[1]=a,st[2]=b,st[3]=c,st[4]=d,st[5]=0,sort(st+1,st+1+4);
	R int res=1,las=1;
	fp(i,2,5)if(st[i]!=st[i-1])res*=fac[i-las],las=i;
	return dv[res];
}
int main(){
//	freopen("testdata.in","r",stdin);
	scanf("%d",&n);
	init();
	fp(i,1,n)scanf("%s",s+1),ins(s);
	fp(i,1,62)fp(d,1,62)fp(l,3,10)if(c[i][d][l])
		fp(j,i,62)if(c[j][d][l]){
			R int ret=mul(c[i][d][l],c[j][d][l]);
			fp(k,j,62)if(c[k][d][l])
				upd(cnt[i][j][k][l],mul(ret,c[k][d][l]));
		}
	fp(i,1,62)fp(j,i,62)fp(k,j,62)fp(l,3,10){
		R int coef=cnt[i][j][k][l];
		if(coef)
			fp(d,k,62)if(cnt[i][j][d][l]&&cnt[i][k][d][l]&&cnt[j][k][d][l]){
				R int ret=1ll*cnt[i][j][d][l]%P*cnt[i][k][d][l]%P*cnt[j][k][d][l]%P;
//				printf("%d %d %d %d %d %d %d %d\n",i,j,k,d,l,ret,coef,calc(i,j,k,d));
				upd(res,1ll*ret*coef%P*calc(i,j,k,d)%P);
			}
	}
	printf("%d\n",res);
	return 0;
}