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
int s[200005];
void add(int a){
	for(int i=a;i<200005;i+=i&-i)
	s[i]++;
}
LL query(int a){
	LL sum=0;
	for(int i=a;i>0;i-=i&-i){
		sum+=s[i];
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	priority_queue<pii> pq;
	LL ans=0;
	for(int i=n;i>=1;i--){
		while(!pq.empty()&&pq.top().x>=i){
			add(pq.top().y);
			pq.pop();
		}
		ans+=query(min(a[i],n));
		pq.push(mp(a[i],i));
	}
	printf("%lld\n",ans);
}