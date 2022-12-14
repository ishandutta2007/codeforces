#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bitset<MN+1>b[27],res;
char st[MN+5],S[MN+5];
int n;
int main()
{
	scanf("%s",st+1);n=strlen(st+1);
	for(int i=1;i<=n;++i) b[st[i]-'a'][i]=1;
	int Q=read();
	while(Q--)
	{
		int op=read();
		if(op==1)
		{
			int x=read();scanf("%s",S+1);
			b[st[x]-'a'][x]=0;
			st[x]=S[1];
			b[st[x]-'a'][x]=1;
		}
		else 
		{
			int l=read(),r=read();scanf("%s",S+1);
			int len=strlen(S+1);
			if(len>r-l+1) {puts("0");continue;} 
			res=b[S[1]-'a'];
			for(int i=2;i<=len;++i) res=res&(b[S[i]-'a']>>i-1);
			res=(res>>l)<<l;
			int len2=MN-(r-len+1);
			res=(res<<len2)>>len2;
			printf("%d\n",res.count()); 
		}
	}
	return 0;
}