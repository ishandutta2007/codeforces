#include<fstream>
#include<queue>

using namespace std;

const char iname[]="input.txt";
const char oname[]="output.txt";

ifstream f(iname);
ofstream g(oname);

int x,y,a[2100][2100];
int i,n,m,k,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
queue<pair<int,int> >Q;

int main()
{
	f>>n>>m>>k;
	for(i=1;i<=k;++i)
		f>>x>>y,Q.push(make_pair(x,y)),a[x][y]=1;

	for(i=0;i<=n+1;++i)
		a[i][0]=a[i][m+1]=1;
	for(i=0;i<=m+1;++i)
		a[0][i]=a[n+1][i]=1;
	while(!Q.empty())
	{
		x=Q.front().first;
		y=Q.front().second;
		Q.pop();
		for(i=0;i<4;++i)
			if(a[x+dx[i]][y+dy[i]]==0)
				a[x+dx[i]][y+dy[i]]=1,Q.push(make_pair(x+dx[i],y+dy[i]));
	}
	g<<x<<" "<<y;
}