#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 300005
using namespace std;
struct srt
{
	int x, y, tp, id; // tp = 1  2 
	bool operator < (const srt &a)const
	{
		if(x + y != a.x + a.y) return x + y < a.x + a.y;
		if(tp != a.tp) return tp < a.tp;
		return x < a.x;
	} 
}p[maxn];
int edpl[maxn][2];
int pls[maxn];
int ans[maxn][2];
queue <int> place;
int main()
{
	int n, w, h;
	scanf("%d%d%d", &n, &w, &h);
	for(int i = 0; i < n; i++)
	{
		int g, pl, t;
		p[i].id = i;
		scanf("%d%d%d", &g, &pl, &t);
		if(g == 1) 
			p[i].x = pl, p[i].y = -t, p[i].tp = 2,
			edpl[i][0] = pl, edpl[i][1] = h;
		else 
			p[i].x = -t, p[i].y = pl, p[i].tp = 1, 
			edpl[i][0] = w, edpl[i][1] = pl;
	}
	sort(p, p + n);
	for(int i = 0; i < n; )
	{
		int edpls = i + 1;
		while(edpls < n && p[edpls].x + p[edpls].y == p[i].x + p[i].y)
			edpls++;
	//	if(edpls != i + 1) 
	//	{
	//		cout<<"FRONT"<<i<<" "<<edpls - 1<<endl;
	//		for(int j = i; j < edpls; j++)
	//			cout<<p[j].x<<" "<<p[j].y<<" "<<p[j].id<<" "<<" "<<p[j].tp<<endl;
	//	}
		int fst = edpls;
		for(int j = i; j < edpls; j++)
			if(p[j].tp == 2)
			{
				fst = j;
				break;
			}
		while(!place.empty()) 
			place.pop();
		int pl1 = i;
		for(int j = fst; j < edpls; j++)
		{
			while(pl1 < fst && p[pl1].x < p[j].x) 
				place.push(p[pl1].id), pl1++;
	//			cout<<"FRONT"<<place.front()<<" "<<pl1<<" "<<endl;
			if(place.empty()) 
				pls[p[j].id] = p[j].id;
			else
				pls[p[j].id] = place.front(), 
		//		cout<<"SET"<<p[j].id<<" "<<place.front()<<endl,
				place.pop(), 
				place.push(p[j].id);
 		}
 		while(pl1 < fst) 
			place.push(p[pl1].id), pl1++;
 		for(int j = i; j < fst; j++)
 			pls[p[j].id] = place.front(), 
 			place.pop();
 	//	if(edpls != i + 1)
 	//	{
 	//		for(int j = i; j < edpls; j++)
 		//		cout<<"PLACE"<<p[j].id<<" "<<pls[p[j].id]<<endl;
	//	 }
	//	 system("pause");
		i = edpls;
	}
//	for(int i = 0; i < n; i++)
//		cout<<i<<" "<<pls[i]<<" "<<edpl[i][0]<<" "<<edpl[i][1]<<endl;
	for(int i = 0; i < n; i++)
		ans[pls[i]][0] = edpl[i][0], 
		ans[pls[i]][1] = edpl[i][1];
	for(int i = 0; i < n; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}