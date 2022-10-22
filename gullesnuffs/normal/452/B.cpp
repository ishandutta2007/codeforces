#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;

using namespace std;

double getDis(double x1, double y1, double x2, double y2){
	double dx=x1-x2;
	double dy=y1-y2;
	return sqrt(dx*dx+dy*dy);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int> > points;
	for(int i=0; i < 7; ++i)
		for(int j=0; j < 7; ++j){
			for(int k=0; k < 2; ++k){
				int x, y;
				if(k){
					x=i-3, y=j-3;
				}
				else{
					x=n+i-3, y=m+j-3;
				}
				if(x < 0 ||y < 0 || x > n || y > m)
					continue;
				points.push_back(make_pair(x, y));
			}
		}
	int best[4];
	double bestVal=0;
	for(int i=0; i < points.size(); ++i)
		for(int j=0; j < points.size(); ++j)
			for(int k=0; k < points.size(); ++k)
				for(int m=0; m < points.size(); ++m){
					double dis=0;
					dis += getDis(points[i].first, points[i].second, points[j].first, points[j].second);
					dis += getDis(points[k].first, points[k].second, points[j].first, points[j].second);
					dis += getDis(points[k].first, points[k].second, points[m].first, points[m].second);
					if(points[i] == points[j] || points[i] == points[k] || points[i] == points[m] || points[j] == points[k] || points[j] == points[m] || points[k] == points[m])
						continue;
					if(dis < bestVal)
						continue;
					bestVal=dis;
					best[0]=i;
					best[1]=j;
					best[2]=k;
					best[3]=m;
				}
	for(int i=0; i < 4; ++i)
		printf("%d %d\n", points[best[i]].first, points[best[i]].second);
}