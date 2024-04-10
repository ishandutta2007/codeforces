#include <bits/stdc++.h>

int n,t,vis[100]={0};
char s[1000000];

int main(){
	scanf("%d%d",&n,&t);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)vis[s[i]-'a']=1;
	int min=-1,max;
	for(int i=0;i<26;++i){
		if (vis[i]){if (min==-1)min=i;max=i;}
	}if (t>n){
		for(int i=1;i<=n;++i)printf("%c",s[i]);
		for(int i=n+1;i<=t;++i)printf("%c",min+'a');
	} else {
		int last=0;
		for(int i=1;i<=t;++i){if (s[i]-'a'<max)last=i;}
	//	assert(last!=0);
		for(int i=1;i<last;++i)printf("%c",s[i]);
		for(int i=s[last]-'a'+1;i<26;++i){
			if (vis[i]){printf("%c",i+'a');break;}}
		for(int i=last+1;i<=t;++i)printf("%c",min+'a');
	}
	return 0;
}