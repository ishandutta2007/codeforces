#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,rez[1005],x,y,k,s,i;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i)
		rez[i]=(1<<25);
	for(i=1;i<=n;++i)
		scanf("%d%d",&x,&y),rez[x]=min(rez[x],y);
	s=0;
	for(i=1;i<=m;++i)
			s+=rez[i];
    printf("%d\n",min(s,k));
}