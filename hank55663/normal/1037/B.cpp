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
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n,s;
	scanf("%d %d",&n,&s);
	int a[200005];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	if(a[n/2]>s){
		LL ans=0;
		for(int i=n/2;i>=0;i--){
			ans+=max(a[i]-s,0);
		}
		printf("%lld\n",ans);
	}
	else if(a[n/2]<s){
		LL ans=0;
		for(int i=n/2;i<n;i++){
			ans+=max(s-a[i],0);
		}
		printf("%lld\n",ans);
	}
	else{
		printf("0\n");
	}
}