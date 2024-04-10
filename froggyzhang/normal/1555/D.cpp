#include<bits/stdc++.h>
using namespace std;
#define N 200010
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
int n,m;
int s[6][N];
char a[N];
const string A[6]={"abc","acb","bac","bca","cab","cba"};
int main(){
	n=read(),m=read();
	scanf("%s",a+1);
	for(int i=0;i<6;++i){
		for(int j=1;j<=n;++j){
			s[i][j]=s[i][j-1]+(a[j]!=A[i][j%3]);	
		}	
	}
	while(m--){
		int l=read(),r=read();
		int ans=1e9;
		for(int i=0;i<6;++i)ans=min(ans,s[i][r]-s[i][l-1]);
		printf("%d\n",ans);
	}
	return 0;
}