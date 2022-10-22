#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[305],t[305];
int len,as,bs,cnt[3];
void pri()
{
	for(int i=1;i<=len;i++)
	{
		printf("%c",t[i]);
	}
	printf("\n");
	fflush(stdout);
}
int main()
{
	for(int i=1;i<=300;i++) printf("a");
	printf("\n");
	fflush(stdout);
	scanf("%d",&as);
	as=300-as;
	for(int i=1;i<=300;i++) printf("b");
	printf("\n");
	fflush(stdout);
	scanf("%d",&bs);
	bs=300-bs;
	len=as+bs;
	int tmp=0;
	for(int i=1;i<=len;i++)
	{
		t[i]='a';
	}
	int now=len-as;
	for(int i=1;i<len;i++)
	{
		t[i]='b';
		pri();
		scanf("%d",&tmp);
		if(tmp==0) return 0; 
		if(tmp>now) 
		{
			ch[i]='a';
			cnt[1]++;
		}
		else 
		{
			ch[i]='b';
			cnt[2]++;
		}
		now=tmp;
	}
	if(cnt[1]==as) ch[len]='b';
	else ch[len]='a';
	for(int i=1;i<=len;i++)
	{
		printf("%c",ch[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}