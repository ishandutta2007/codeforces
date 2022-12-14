#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

map<int,int> mp;
int cnt=0;
int n;
char s[100];
int num[5000];

int main()
{
	n=read();scanf("%s",s);
	for(int i=1;i<=n;i++)
	{
	    scanf("%s",s+1);int x=0;
		for(int i=1;i<=3;i++) x=x*27+s[i]-'A'+1;
		if(!mp[x]) mp[x]=++cnt;
		num[mp[x]]++;x=0;
		for(int i=6;i<=8;i++) x=x*27+s[i]-'A'+1;
		if(!mp[x]) mp[x]=++cnt;
		num[mp[x]]--;
	}
	for(int i=1;i<=cnt;i++) if(num[i]!=0) return 0*puts("contest");
	puts("home");
	return 0;
}