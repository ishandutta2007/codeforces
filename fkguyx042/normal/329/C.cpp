#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<map>

#define N 100005
using namespace std;
int i,j,m,n,p,k,id[N],x,y;
map<int,int>mp[N];
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=m;++i)
	 {
	 	 scanf("%d%d",&x,&y);
	 	 mp[x][y]=mp[y][x]=1;
	 }
	 for (i=1;i<=n;++i) id[i]=i;
	 srand((int)time(0));
	 int limit=3000000/m;
	 for (;limit--;)
	 {
	 	 random_shuffle(id+1,id+n+1); id[0]=id[n];
	 	 int tot=0;
	 	 for (i=0;i<n;++i) if (!mp[id[i]][id[i+1]]) ++tot;
	 	 if (tot<m) continue;
	 	 for (i=0;i<n&&m;++i)
	 	   if (!mp[id[i]][id[i+1]]) --m,printf("%d %d\n",id[i],id[i+1]);
	 	 return 0;
	 }
	 printf("-1\n");
}