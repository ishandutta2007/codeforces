#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
using namespace std;
typedef long long LL;
int main(){
	int n,k,l;
	scanf("%d %d %d",&n,&k,&l);
	int a[100005];
	for(int i=0;i<n*k;i++)
	scanf("%d",&a[i]);
	sort(a,a+n*k);
	if(a[n-1]-a[0]>l){
		printf("0\n");
		return 0;
	}
	LL ans=0;
	int last=n*k;
	for(int i=0;i<n;i++){
		last=min(last-1,(n-i-1)*k);
		for(;last>=0;last--){
			if(a[last]-a[0]<=l){
				ans+=a[last];
				break;
			}	
		}
	}
	printf("%lld\n",ans);
}