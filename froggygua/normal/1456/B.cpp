#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
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
int s[N],a[N],n,ans;
int main(){
	n=read();
	if(n>70){
		return !printf("1\n");
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]^a[i];
	}
	ans=n+233;
	for(int i=1;i<n;++i){
		for(int j=i;j<=n;++j){
			 for(int l=j+1;l<=n;++l){
			 	for(int r=l;r<=n;++r){
			 		if((s[r]^s[l-1])<(s[j]^s[i-1])){
			 			ans=min(ans,j-i+r-l);
			 		}
			 	}
			}
		}
	}
	printf("%d\n",ans>n?-1:ans);
	return 0;
}