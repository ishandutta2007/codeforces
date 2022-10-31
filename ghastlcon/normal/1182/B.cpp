#include<bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;

int n,m,a[maxn][maxn];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

void input()
{
	int i,j;char c;

	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			while((c=getchar()) !='.' && c!='*');
			a[i][j]=(c=='*');
		}
	}
}

bool leg(int x,int y){return x>=0 && x<n && y>=0 && y<m;}

void find()
{
	int i,j,d;

	for(i=1;i<n-1;i++) for(j=1;j<m-1;j++) if(a[i][j])
	{
		for(d=0;d<4;d++) if(!a[i+dx[d]][j+dy[d]]) goto fail;
		for(d=0;d<4;d++)
		{
			int x=i+dx[d],y=j+dy[d];
			while(leg(x,y) && a[x][y]) a[x][y]=0,x+=dx[d],y+=dy[d];
		}
		a[i][j]=0;

		for(int x=0;x<n;x++) for(int y=0;y<m;y++) 
		{
			if(a[x][y]) puts("NO"),exit(0);
		}
		puts("YES");exit(0);

		fail:;
	}
	puts("NO");
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("inp.txt","r",stdin);
	freopen("oup.txt","w",stdout);
	#endif

	input();
	find();
	
	return 0;
}