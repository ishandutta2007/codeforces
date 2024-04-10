#include<stdio.h>
#include<map>
#include<set>
#include<queue>
#include<vector> 
#include<string>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define rank Rank
using namespace std;
typedef long long LL;
vector<pair<pii,int> > v[100005];
int main()
{
//	int t;
//	scanf("%d",&t);
//	while(t--){
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<100005;i++)
		v[i].clear();
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			v[a].pb(mp(mp(b,c),0));
			v[b].pb(mp(mp(a,c),0));
		} 
		for(int i=1;i<=k;i++){
			int s,y;
			scanf("%d %d",&s,&y);
			v[1].pb(mp(mp(s,y),i));
		} 
		priority_queue<pair<pll,int>,vector<pair<pll,int> >,greater<pair<pll,int> > > pq;
		pq.push(mp(mp(0,1),0));
		LL d[100005];
		MEM(d);
		int visit[100005];
		MEM(visit);
		int use[100005]; 
		MEM(use);
		while(!pq.empty()){
			pair<pll,int> p = pq.top();
			pq.pop();
			if(visit[p.x.y])
			continue;
			d[p.x.y]=p.x.x;
			visit[p.x.y]=1;
			use[p.y]=1;
			int x=p.x.y;
			LL len=p.x.x;
			for(vector<pair<pii,int> >::iterator it=v[x].begin();it!=v[x].end();it++){
				if(!visit[it->x.x]){
					pq.push(mp(mp(it->x.y+len,it->x.x),it->y));
				}
			}
		}
		int ans=0;
		for(int i=1;i<=k;i++){
			if(!use[i])
			ans++;
		}
		printf("%d\n",ans);
//	} 
}