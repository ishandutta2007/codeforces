#include <bits/stdc++.h>

using namespace std;
#define pb insert
#define pbb push_back

int n,m;
set<int>edge[100005];
int cur;

bool rec(int x,int pre)
{
	vector<int>vec;
	int up = cur++;
	while(1)
 	{
 		set<int>::iterator it = edge[x].begin();
 		if(it == edge[x].end()) break;
 		int y = *it;
 		edge[x].erase(edge[x].find(y));
 		edge[y].erase(edge[y].find(x));
 		bool ac = rec(y,x);
 		if(!ac) vec.pbb(y);
 	}
 	for(int i=0;i+1<vec.size();i+=2)
 	{
 		printf("%d %d %d\n",vec[i],x,vec[i+1]);
 	}
 	if(vec.size()%2==0) return 0;
 	printf("%d %d %d\n",vec[vec.size()-1],x,pre);
 	return 1;
 }
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	if(m%2==1) puts("No solution");
	else rec(1,1);
	return 0;
	puts("");
}