#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
struct node
{
	int x,y;
	int dir;//0:N 1:S 2:W 3:E
};
bool operator < (node x,node y)
{
	if(x.x!=y.x) return x.x<y.x;
	if(x.y!=y.y) return x.y<y.y;
	if(x.dir!=y.dir) return x.dir<y.dir;
	return false;
}
int n,len,x,y,ans;
char s[200005];
map<node,bool> mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		mp.clear();
		ans=x=y=0;
		scanf("%s",s+1);
		len=strlen(s+1);
		for(int j=1;j<=len;j++)
		{
			ans+=5;
			if(s[j]=='N')
			{
				if(mp[(node){x,y,0}]) ans-=4;
				mp[(node){x,y,0}]=true;
				mp[(node){x+1,y,1}]=true;
				x++;
			}
			if(s[j]=='S')
			{
				if(mp[(node){x,y,1}]) ans-=4;
				mp[(node){x,y,1}]=true;
				mp[(node){x-1,y,0}]=true;
				x--;
			}
			if(s[j]=='W')
			{
				if(mp[(node){x,y,3}]) ans-=4;
				mp[(node){x,y,3}]=true;
				mp[(node){x,y+1,4}]=true;
				y++;
			}
			if(s[j]=='E')
			{
				if(mp[(node){x,y,4}]) ans-=4;
				mp[(node){x,y,4}]=true;
				mp[(node){x,y-1,3}]=true;
				y--;
			}
		}
		printf("%d\n",ans); 
	}
}