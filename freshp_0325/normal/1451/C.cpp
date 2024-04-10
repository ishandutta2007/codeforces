#include<bits/stdc++.h>
using namespace std;
int a[29],b[29],q,n,k;
char s[1000005],t[1000005];
int main(){
	scanf("%d",&q);
	while(q-->0)
	{
		scanf("%d %d",&n,&k);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=1;i<=n;++i)	++a[int(s[i]-'a')];
		for(int i=1;i<=n;++i)	++b[int(t[i]-'a')];
		for(int i=0;i<=25;++i)
		{
			int tmp=min(a[i],b[i]);
			a[i]-=tmp;
			b[i]-=tmp;
		}
		for(int i=0;i<=25;++i)
		{
			int tmp=min(a[i],b[i]);
			a[i]-=tmp;
			b[i]-=tmp;
			a[i+1]+=a[i]/k*k;
			a[i]-=a[i]/k*k;
		}
		bool flag=false;
		for(int i=0;i<=25;++i)	if(a[i] || b[i]){flag=true;break;}
		puts(flag?"No":"Yes");
	}
	return 0;
}