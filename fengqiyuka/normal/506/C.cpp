#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+100;
ll h[N],a[N],H[N];
struct dui{
	ll x1,x2;
	friend bool operator <(dui n1,dui n2){
		return (n1.x1>n2.x1);
	}
};
priority_queue<dui> q;
ll mymax(ll x,ll y) {return x>y?x:y;}
int main()
{
	int n,m,k,p;ll Max=0;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&h[i],&a[i]);
	ll l=0,r=1e14,ans;
	while(l<=r){
		ll mid=(l+r)>>1;
		for(int i=1;i<=n;i++){
			H[i]=0;
			dui t;t.x1=mid/a[i];t.x2=i;
			if(mid-a[i]*m<h[i]) q.push(t);
		}
		bool pd=true;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k;j++){
				if(q.empty()) break;
				dui t=q.top();q.pop();
				if(t.x1<i) {pd=false;break;}
				H[t.x2]++;
				if(mid-a[t.x2]*m+H[t.x2]*p<h[t.x2]){
					t.x1=i+(mid-a[t.x2]*i+H[t.x2]*p)/a[t.x2];
					q.push(t);
				}
			}
			if(!pd) break;
		}
		if(!q.empty()) pd=false;
		while(!q.empty()) q.pop();
		if(pd) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}