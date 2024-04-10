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
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	priority_queue<pii,vector<pii>,less<pii> > pq;
	vector<int> v;
	LL ans=0;
	LL sum=0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		pq.push(mp(a,i));
		sum+=a;
		if(i>k){
			sum-=pq.top().x;
			v.pb(pq.top().y);
			pq.pop();
		}
		ans+=sum;
	}
	while(!pq.empty()){
		sum-=pq.top().x;
		v.pb(pq.top().y);
		pq.pop();
		ans+=sum;
	}
	printf("%I64d\n",ans);
	int hi[3000005];
	for(int i=0;i<v.size();i++)
	hi[v[i]]=i+k+1;
	for(int i=1;i<=n;i++)
	printf("%d ",hi[i]);
}