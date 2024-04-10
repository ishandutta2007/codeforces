#include <bits/stdc++.h>
int n,cnt;
char s[100000];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		int k=s[i]-'0';
		if (k==8)cnt++;
	}printf("%d",std::min(cnt,n/11));
	return 0;
}