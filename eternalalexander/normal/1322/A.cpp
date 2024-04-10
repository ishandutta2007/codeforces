#include <bits/stdc++.h>
int n,a[1000005],ans;
char s[1000005];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		a[i]=a[i-1];
		if(s[i]=='(')a[i]++;
		else a[i]--;
		if(a[i]<0||a[i]==0&&a[i-1]<0)ans++;
	}if(a[n]!=0)printf("-1");
	else printf("%d",ans);
	return 0;
}