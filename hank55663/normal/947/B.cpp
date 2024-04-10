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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int v[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&v[i]);
	int t[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&t[i]);
	multiset<LL> s;
	LL now=0;
	for(int i=0;i<n;i++){
		LL ans=0;
		s.insert(v[i]+now);
		while(!s.empty()&&*s.begin()<=t[i]+now)ans+=*s.begin()-now,s.erase(s.begin());
		printf("%lld ",ans+(LL)s.size()*t[i]);
		now+=t[i];
	}
}