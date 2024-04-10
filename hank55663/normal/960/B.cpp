#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n,opa,opb;
	scanf("%d %d %d",&n,&opa,&opb);
	int a[1005],b[1005];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int j=0;j<n;j++){
		scanf("%d",&b[j]);
	}
	priority_queue<int> pq;
	for(int i=0;i<n;i++)
	pq.push(abs(a[i]-b[i]));
	for(int i=0;i<opa+opb;i++){
		int x=pq.top();
		pq.pop();
		x--;
		pq.push(abs(x));
	}
	LL ans=0;
	while(!pq.empty()){
		ans+=sqr((LL)pq.top());
		pq.pop();
	}
	printf("%lld\n",ans);
}