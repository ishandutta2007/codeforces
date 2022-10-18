#include <bits/stdc++.h>

char s[110];
int ans=0;

int main(){
	scanf("%s",s+1);
	int n=std::strlen(s+1);
	if (n==1)printf("%s",s+1);
	else{
		for(int i=n;i>1;i--){
			if (s[i]=='9')ans-=9;
			else break;
		}
		for(int i=2;i<n;++i)ans+=s[i]-'0'+9;
		ans+=s[1]-'0'-1;
		ans+=s[n]-'0'+10;
		printf("%d",ans);
	}
	return 0;
}