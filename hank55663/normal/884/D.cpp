#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int a[200005];
int main(){
	int n;
	scanf("%d",&n);
	priority_queue<LL,vector<LL> ,greater<LL> > pq;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),pq.push(a[i]);
	if(n%2==0)
	pq.push(0);
	LL sum=0;
	while(!pq.empty()){
		if(pq.size()==1)
		break;
		LL x=pq.top();
		pq.pop();
		LL y=pq.top();
		pq.pop();
		LL z=pq.top();
		pq.pop();
		sum=sum+(x+y+z);
		pq.push(x+y+z);
	}
	printf("%I64d\n",sum);
	return 0;
}