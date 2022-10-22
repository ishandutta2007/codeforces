#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int n,m,a[100005],l[100005][2],r[100005][2],g[2][100005];
bool inside(int x,int op,int val){return l[x][op]<=val && val<=r[x][op];}
void Solve(int now,int op)
{
	if(!now)	return ;
	int lst=g[op][now];
	Solve(lst,op^1);
	for(int i=lst+1;i<=now;++i)	printf("%d ",op);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<=1;++j)	scanf("%d %d",&l[i][j],&r[i][j]);
	}
	if(l[1][0] && l[1][1])	return puts("No")&0;
	set<pair<int,int>> S[2];
	if(inside(1,0,a[1]) && !l[1][1])	S[0].insert(mp(0,0));
	if(inside(1,1,a[1]) && !l[1][0])	S[1].insert(mp(0,0));
	for(int i=2;i<=n;++i)
	{
		int S1e=!S[1].empty(),S0e=!S[0].empty();
		if(S0e)	S[1].insert(mp(a[i-1],i-1));
		if(S1e)	S[0].insert(mp(a[i-1],i-1));
		if(inside(i,0,a[i]))
		{
			while(!S[0].empty())
			{
				if(inside(i,1,(*S[0].begin()).first))	break;
				S[0].erase(S[0].begin());
			}
			while(!S[0].empty())
			{
				if(inside(i,1,(*S[0].rbegin()).first))	break;
				S[0].erase(*S[0].rbegin());
			}
		}
		else	S[0].clear();
		if(inside(i,1,a[i]))
		{
			while(!S[1].empty())
			{
				if(inside(i,0,(*S[1].begin()).first))	break;
				S[1].erase(S[1].begin());
			}
			while(!S[1].empty())
			{
				if(inside(i,0,(*S[1].rbegin()).first))	break;
				S[1].erase(*S[1].rbegin());
			}
		}
		else	S[1].clear();
		if(!S[0].empty())	g[0][i]=(*S[0].begin()).second;
		if(!S[1].empty())	g[1][i]=(*S[1].begin()).second;
	}
	if(!S[0].empty())	puts("Yes"),Solve(n,0);
	else if(!S[1].empty())	puts("Yes"),Solve(n,1);
	else	puts("No");
	return 0;
}