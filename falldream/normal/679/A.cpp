#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MN=100;char s[101];
int num,q[105],top=0;
int main()
{	
	for(int i=2;i<=MN;++i)
	{
		q[++top]=i;
		for(int j=2;j<i;++j)
			if(i%j==0) {--top;break;}
	}
	for(int i=1;q[i]<=50;++i)
		if(printf("%d\n",q[i]),fflush(stdout),scanf("%s",s+1),s[1]=='y') 
		{
			if(++num>=2) return 0*puts("composite");
			if(q[i]*q[i]<=100) 
				if(printf("%d\n",q[i]*q[i]),fflush(stdout),scanf("%s",s+1),s[1]=='y') return 0*puts("composite");	
		}
	puts("prime");
	return 0;
}