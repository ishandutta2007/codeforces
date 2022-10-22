#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int inf=(1<<25);
const int maxn=110000;

char a[maxn],b[maxn],x,y;
int cost[505][505],m,i,aux,k,j,rez,ok,mint,w;
int main()
{
   // freopen("b.in","r",stdin);
	fgets(a,sizeof(a),stdin);
	fgets(b,sizeof(b),stdin);
	scanf("%d\n",&m);
	for(i='a';i<='z';++i)
		for(j='a';j<='z';++j)
			if(i!=j)
				cost[i][j]=inf;
	while(m--)
		scanf("%c %c",&x,&y),scanf("%d\n",&aux),cost[x][y]=min(cost[x][y],aux);
	
	for(k='a';k<='z';++k)
		for(i='a';i<='z';++i)
			for(j='a';j<='z';++j)
				if(cost[i][k]+cost[k][j]<cost[i][j])
					cost[i][j]=cost[i][k]+cost[k][j];

	for(i=0;a[i]!='\n'&&a[i];++i)
		if(b[i]==0||b[i]=='\n')
		{
			ok=1;
			//fprintf(stderr,"Facem break la pozitia %d ca s-a terminat b",i);
			break;
		}
		else
		{
			mint=inf;
			for(j='a';j<='z';++j)
				if(cost[a[i]][j]+cost[b[i]][j]<mint)
					mint=cost[a[i]][j]+cost[b[i]][j],w=j;
			if(mint==inf)
			{
				ok=1;
				//fprintf(stderr,"Facem break la pozitia %d\n",i);
				break;
			}
			rez+=mint;
			a[i]=w;
		}
	a[i]=0;
	if(b[i]!='\n'&&b[i])
		ok=1;
	if(ok==0)
	{
		printf("%d\n",rez);
		printf("%s",a);
		return 0;
	}
	printf("-1");
}