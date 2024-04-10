#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int t,n,a[200002][26],m,k,ans,l,r;
char s[200002];
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=25;++j)a[i][j]=a[i-1][j];
		++a[i][s[i]-'a'];
	}
scanf("%d",&t);
while(t--){
	scanf("%d%d",&l,&r);
	if(s[l]!=s[r]||l==r)puts("Yes");
	else{
		int cnt=0;
		for(int i=0;i<=25;++i)if(a[r][i]-a[l-1][i])++cnt;
		if(cnt>2)puts("Yes");
		else puts("No");
	}
}
}