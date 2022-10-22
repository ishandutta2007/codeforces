#include<bits/stdc++.h>
using namespace std;
char s[55];
int st[28];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		memset(st,0,sizeof st);
		for(int i=1;i<=n;++i)	++st[s[i]-'a'+1];
		int ans=0,stp=0;
		for(int i=1;i<=26;++i)	if(st[i]>=2)	++ans;else if(st[i]==1)	++stp;
		printf("%d\n",ans+stp/2);
	}
	return 0;
}