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
	int n,t;
	scanf("%d %d",&n,&t);
	int a[200005];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]-=i;
		if(a[i]<0)
		a[i]=0;
	}
	int ans=0;
	priority_queue<int> pq;
	for(int i=1;i<=n;i++){
		pq.push(a[i]);
		while(!pq.empty()&&pq.top()>=t-i)pq.pop();
		ans=max(ans,(int)pq.size());
	}
	printf("%d\n",ans);
}