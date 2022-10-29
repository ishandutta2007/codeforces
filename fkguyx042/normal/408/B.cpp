#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int a[1005],b[1005];
int f[1005][1005],ta=0,tb=0,ans;


inline int cmp(const char &a,const char &b)
{
	return a<b;
}


int main()
{
	char x=getchar();
	while(x!='\n')a[x-'a']++,x=getchar();
	x=getchar();
	while(x!='\n'&&x!=-1)b[x-'a']++,x=getchar();
	for(int i=0;i<=26;i++)
	if(b[i]&&!a[i])
	{
		printf("-1\n");return 0;
	}
	for(int i=0;i<=26;i++)ans+=min(a[i],b[i]);
	if(!ans)printf("-1\n");else printf("%d\n",ans);
	return 0;
}