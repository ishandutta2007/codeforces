#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	LL ans=0;
	pq.push(mp(1e9,0));
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a-pq.top().x>0)
		{
			ans+=a-pq.top().x;
			//printf("%d %d\n",a,pq.top());
			pii p=pq.top();
			pq.pop();
			if(p.y==-1){ 
				p.y=0;
				pq.push(p);
			} 
			pq.push(mp(a,-1)); 
		}
		else
		pq.push(mp(a,0));
	} 
	printf("%I64d\n",ans);
}