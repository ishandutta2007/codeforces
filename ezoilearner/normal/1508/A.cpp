#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n;
#define Maxn 200010
char s[3][Maxn];

char ans[Maxn];

int i=0,j=0,k=0,len=0;
char p[3][Maxn];int all;int bb[3];

int main(){
	int T;rd(T);
	while(T--){
		rd(n);len=0;
		rep(i,0,2)scanf("%s",s[i]);i=0;j=0;k=0;
		while(i<2*n&&j<2*n&&k<2*n){
			int cnt[2];cnt[0]=cnt[1]=0;
			int a=s[0][i]-'0',b=s[1][j]-'0',c=s[2][k]-'0';
			cnt[a]++;cnt[b]++;cnt[c]++;int mx=0;
			if(cnt[0]<cnt[1])mx=1;
			if(a==mx)i++;if(b==mx)j++;if(c==mx)k++;
			ans[++len]='0'+mx;
		}
		all=0;
		if(i<2*n){
			all++;bb[all]=2*n-i;
			rep(l,i,2*n-1)p[all][l-i+1]=s[0][l];
		}
		if(j<2*n){
			all++;bb[all]=2*n-j;
			rep(l,j,2*n-1)p[all][l-j+1]=s[1][l];
		}
		if(k<2*n){
			all++;bb[all]=2*n-k;
			rep(l,k,2*n-1)p[all][l-k+1]=s[2][l];
		}
		if(all>=2){
			int at=1;
			if(bb[2]<bb[1])at=2;
			rep(l,1,bb[at])ans[++len]=p[at][l];
		}
		rep(i,1,len)putchar(ans[i]);puts("");
	}
	return 0;
}