#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
using namespace std;
int T,x,l,n,ans,f[N],r[N],s[N],t[N];char S[N],st[N];
int main(){
	scanf("%s",S);l=strlen(S);
	rep(i,1,l)s[i]=S[i-1]-'A';
	scanf("%d",&T);
	rep(o,1,T){
		scanf("%s",st);n=strlen(st);
		if(n<2)continue;
		rep(i,1,n)t[i]=st[i-1]-'A';
		t[0]=t[n+1]=-1;f[1]=0;
		rep(i,2,n){x=f[i-1];
			while(x&&t[x+1]!=t[i])x=f[x];
			if(t[x+1]==t[i])f[i]=x+1;else f[i]=0;
		}x=0;
		rep(i,1,l){
			while(x&&t[x+1]!=s[i])x=f[x];
			if(t[x+1]==s[i])x++;r[i]=x;
		}f[n]=n+1;
		rep(i,1,l)if(r[i-1]>r[i])r[i]=r[i-1];
		dep(i,n-1,1){x=f[i+1];
			while(x<=n&&t[x-1]!=t[i])x=f[x];
			if(t[x-1]==t[i])f[i]=x-1;else f[i]=n+1;
		}x=n+1;
		dep(i,l,1){
			while(x<=n&&t[x-1]!=s[i])x=f[x];
			if(t[x-1]==s[i])x--;
			if(r[i-1]+1>=x){ans++;break;}
		}
	}
	printf("%d\n",ans);
}