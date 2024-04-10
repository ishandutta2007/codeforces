#include<cstdio>
#include<cstring>
main(){
	int n,ans=0;
	char s[2010];
	scanf("%d %s",&n,s);
	int len=strlen(s);
	int pos=0;
	while(pos<len){
		if(pos>=3)ans+=s[pos-1]==s[pos-2]&&s[pos-2]==s[pos-3];
		pos+=n;
	}
	printf("%d\n",ans);
}