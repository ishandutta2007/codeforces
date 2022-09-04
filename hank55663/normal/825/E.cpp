#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b)
#define pii pair<int,int>
#define pdd pair<double,double>
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
#define seg pair<pii,pii>
//#define M 1000005
//#define pi 3.14159265359
#define rank Rank
using namespace std;
typedef long long LL;
vector<int> v[100005];
int in[100005];
int main()
{	

	int n,m;
	scanf("%d %d",&n,&m);
	MEM(in);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[b].pb(a);
		in[a]++;
	}
	priority_queue<int,vector<int>,less<int> > pq;
	for(int i=1;i<=n;i++)
	if(in[i]==0)
	pq.push(i);
	int index=n;
	int ans[100005];
	while(!pq.empty()){
		int x=pq.top();
		pq.pop();
		ans[x]=index--;
		for(vector<int>::iterator it=v[x].begin();it!=v[x].end();it++){
			in[*it]--;
			if(in[*it]==0)
			pq.push(*it);
		}
	} 
/*	for(int i=1;i<=n;i++)
		for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
			assert(ans[i]<ans[*it]);*/
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
}