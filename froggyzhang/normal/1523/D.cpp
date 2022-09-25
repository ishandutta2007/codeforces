#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,p,a[200020][66],sum[1<<15],mx,ans[233];
char s[66];
int t[2333];
mt19937 rnd(time(0));
int main(){
	n=read(),m=read(),p=read();
	for(int i=0;i<n;++i){
		scanf("%s",s);
		for(int j=0;j<m;++j)a[i][j]=s[j]-'0';
	}
	for(int T=1;T<=22;++T){
		int u=rnd()%n;
		p=0;
		for(int j=0;j<m;++j){
			if(a[u][j]){
				t[p++]=j;
			}
		}
		int tot=(1<<p)-1;
		for(int i=0;i<=tot;++i){
			sum[i]=0;
		}
		for(int i=0;i<n;++i){
			int st=0;
			for(int j=0;j<p;++j)if(a[i][t[j]])st|=1<<j;
			++sum[st];	
		}
		for(int i=0;i<p;++i){
			for(int s=0;s<=tot;++s){
				if(!(s>>i&1))sum[s]+=sum[s^(1<<i)];
			}
		}
		for(int s=0;s<=tot;++s){
			if(sum[s]>=(n+1)/2&&__builtin_popcount(s)>mx){
				mx=__builtin_popcount(s);
				for(int j=0;j<m;++j)ans[j]=0;
				for(int j=0;j<p;++j){
					if(s>>j&1){
						ans[t[j]]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<m;++i){
		putchar(ans[i]+'0');
	}
	return 0;
}