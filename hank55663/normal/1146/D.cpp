/*#include<bits/stdc++.h>
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
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int vis[10000005];
int main() {
	int m,a,b;
	scanf("%d %d %d",&m,&a,&b);
	int gcd=__gcd(a,b);
	LL ans=0;
	queue<int> q;
	priority_queue<int,vector<int>,greater<int> > pq;
	q.push(0);
	vis[0]=1;
	int now=1;

	for(int i = gcd;i<=m;i++){
		//printf("%d\n",i);
		while(!pq.empty()&&pq.top()<=i){
			q.push(pq.top());
			vis[pq.top()]=1;
			now++;
			pq.pop();
		}
		while(!q.empty()){
			int x=q.front();
			//printf("%d\n",x);
			q.pop();
			if(x+a<=i&&!vis[x+a]){
				vis[x+a]=1;
				now++;
				q.push(x+a);
			}
			if(x+a>i){
				pq.push(x+a);
			}
			if(x-b>=0&&!vis[x-b]){
				vis[x-b]=1;
				now++;
				q.push(x-b);
			}
		}
		if(now==i/gcd+1){
			//printf("%lld\n",ans);
			ans+=(LL)(i/gcd+2+m/gcd)*(m/gcd-i/gcd-1)/2*gcd;
			//printf("%lld\n",ans);
			LL x=(i/gcd+1)*gcd;
			LL y=(m/gcd)*gcd-1;
			//printf("%d %d %d\n",x,y,i);
			ans+=(LL)(m-y)*(m/gcd+1);
			//printf("%lld\n",ans);
			ans+=(LL)(x-i)*(i/gcd+1);
			break;
		}
		ans+=now;
		//printf("%d\n",now);
		
	}
	printf("%lld\n",ans+min(gcd,m+1));
	return 0;
}
/*
0 1
1 1
2 1
3 2
4 2
5 2

6 3

*/
/*
 9 10 11
*/