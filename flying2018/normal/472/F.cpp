#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 10010
#define D 30
#define MP make_pair
#define P pair<int,int>
using namespace std;
vector<P >ans,res;
int bas[D+2],sbas[D+2];
int pos[N],x[N],y[N],sy[N];
int insert(int p)
{
	int s=0;
	for(int i=D;i>=0;i--)
	if((x[p]>>i)&1)
	{
		if(bas[i]) x[p]^=x[bas[i]],s^=sbas[i];
		else
		{
			bas[i]=p;
			sbas[i]=s|(1<<i);
			return i;
		}
	}
	return -1;
}
bool find(int &y,int &s)
{
	for(int i=D;i>=0;i--)
	if((y>>i)&1)
	{
		if(bas[i]) y^=x[bas[i]],s^=sbas[i];
		else return false;
	}
	return true;
}
int q[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++) scanf("%d",&y[i]);
	for(int i=1;i<=n;i++) pos[i]=insert(i);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int s=0;
		if(!find(y[i],s)){puts("-1");return 0;}
		if(pos[i]>=0){q[cnt]=i;sy[cnt++]=s;continue;}
		ans.push_back(MP(i,i));
		for(int j=D;j>=0;j--)
		if((s>>j)&1) ans.push_back(MP(i,bas[j]));
	}
	for(int i=0;i<cnt;i++)
	{
		int s=sy[i];
		sy[i]=0;
		for(int j=0;j<cnt;j++)
		if((s>>pos[q[j]])&1) sy[i]|=1<<j;
	}
	for(int i=0;i<cnt;i++)
	{
		if(!((sy[i]>>i)&1))
		{
			for(int j=i+1;j<cnt;j++)
			if((sy[j]>>i)&1)
			{
				res.push_back(MP(q[i],q[j]));
				res.push_back(MP(q[j],q[i]));
				res.push_back(MP(q[i],q[j]));
				swap(sy[i],sy[j]);
				break;
			}
		}
		if((sy[i]>>i)&1)
			for(int j=i+1;j<cnt;j++)
				if((sy[j]>>i)&1) res.push_back(MP(q[j],q[i])),sy[j]^=sy[i];
	}
	reverse(res.begin(),res.end());
	for(int i=0;i<cnt;i++)
	{
		if(!((sy[i]>>i)&1)) ans.push_back(MP(q[i],q[i]));
		for(int j=i+1;j<cnt;j++) if((sy[i]>>j)&1) ans.push_back(MP(q[i],q[j]));
	}
	for(P i:res) ans.push_back(i);
	printf("%d\n",ans.size());
	for(P i:ans) printf("%d %d\n",i.first,i.second);
	return 0;
}