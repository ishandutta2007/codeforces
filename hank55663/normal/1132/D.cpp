#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	LL a[200005];
	LL b[200005];
	for(int i =0;i<n;i++)
	scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
	scanf("%lld",&b[i]);
	LL Max=2e12,Min=-1;
	while(Max>Min+1){
		LL mid=(Max+Min)/2;
		LL tempa[200005];
		priority_queue<pll,vector<pll>,greater<pll> > pq;
		for(int i=0;i<n;i++){
			pq.push(mp(a[i]/b[i],i));
			tempa[i]=a[i];
		}
		int ok=1;
		for(int i=0;i<k-1;i++){
			pll p=pq.top();
			pq.pop();
			if(p.x>k)
			break;
			if(p.x<i){
				//printf("%d\n",i);
				ok=0;
				break;
			}
			tempa[p.y]+=mid;
			pq.push(mp(tempa[p.y]/b[p.y],p.y));
		}
		//printf("%lld %d\n",mid,ok);
		for(int i =0;i<n;i++){
			if(tempa[i]/b[i]<k-1){
				ok=0;
				break;
			}
		}
		if(ok){
			Max=mid;
		}
		else{
			Min=mid;
		}
	}
	if(Max==2e12)
	printf("-1\n");
	else
	printf("%lld\n",Max);
}