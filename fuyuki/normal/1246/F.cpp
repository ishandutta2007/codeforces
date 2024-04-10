#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define once(x) ans+=Sl[x][cl[i]]+Sr[x][cr[i]],cl[i]=Fl[x][cl[i]],cr[i]=Fr[x][cr[i]]
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
const int N=1e5+2,alpha=26,logN=20;
int n,cnt[alpha];
char a[N];
int pre[N][alpha],nxt[N][alpha],L[N],R[N];
int Fl[logN][N],Fr[logN][N],cl[N],cr[N],ext[N];
ll Sl[logN][N],Sr[logN][N],use[N],ans;
V input(){for(re char ch=gc;ch>='a';ch=gc)a[++n]=ch;}
V init(){
	FOR(i,1,n)a[i]-='a',cl[i]=cr[i]=i;
	FOR(i,0,25)pre[0][i]=1,nxt[n+1][i]=n;
	FOR(i,1,n){
		FOR(j,0,25)pre[i][j]=pre[i-1][j];
		L[i]=pre[i][a[i]],pre[i][a[i]]=i;
	}
	ROF(i,n,1){
		FOR(j,0,25)nxt[i][j]=nxt[i+1][j];
		R[i]=nxt[i][a[i]],nxt[i][a[i]]=i;
	}
	FOR(i,1,n)sort(nxt[i],nxt[i]+26),sort(pre[i],pre[i]+26);
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
V work(){
	FOR(i,1,n)Fl[0][i]=n,Fr[0][i]=1;
	FOR(t,1,26){
		FOR(i,1,n){
			Fl[0][i]=min(Fl[0][i],L[nxt[i][t-1]]);
			Fr[0][i]=max(Fr[0][i],R[pre[i][26-t]]);
			Sl[0][i]=i-1,Sr[0][i]=n-i;
		}
		FOR(j,1,19)FOR(i,1,n){
			Fl[j][i]=Fl[j-1][Fl[j-1][i]];
			Fr[j][i]=Fr[j-1][Fr[j-1][i]];
			Sl[j][i]=Sl[j-1][i]+Sl[j-1][Fl[j-1][i]];
			Sr[j][i]=Sr[j-1][i]+Sr[j-1][Fr[j-1][i]];
		}
		rnt r=0,now=0;
		FOR(i,1,n){
			while(r<n&&now+!cnt[a[r+1]]<=t)now+=!cnt[a[++r]]++;
			ext[i]=r,now-=!--cnt[a[i]];
		}
		FOR(i,1,n){
			ROF(j,19,0)if(Fr[j][cr[i]]<=ext[Fl[j][cl[i]]])once(j);
			if(cr[i]<=ext[cl[i]])once(0);
		}
	}
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}