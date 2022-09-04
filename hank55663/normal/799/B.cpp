//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 300005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
struct clo{
	int f,b,p,i;
};
bool operator>(const clo &a,const clo &b){
	return a.p>b.p;
} 
int main() {
	int n;
	scanf("%d",&n);
	int visit[N];
	MEM(visit);
	priority_queue<clo,vector<clo>,greater<clo> > pq[4];
	clo c[N];
	for(int i=0;i<n;i++)
	scanf("%d",&c[i].p);
	for(int i=0;i<n;i++)
	scanf("%d",&c[i].f);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i].b);
		c[i].i=i;
	}
	for(int i=0;i<n;i++){
		pq[c[i].f].push(c[i]);
		pq[c[i].b].push(c[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int color;
		scanf("%d",&color);
		while(!pq[color].empty()&&visit[pq[color].top().i])pq[color].pop();
		if(pq[color].empty())
			printf("-1\n");
		else{
			printf("%d ",pq[color].top().p);
			visit[pq[color].top().i]=1;
			pq[color].pop();
		}
	}
} 
//1 1 2 6 3 8 4 11 5 17 6 15 7 13 8 25 9 22 10 27
//1
//2 4 6 8 10
//3 6 9
//4 2 6 8 10
//5 5 10
//6 2 3 4 6 8 10