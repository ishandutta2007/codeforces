#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int n,q,k;
	scanf("%d %d %d",&n,&q,&k);
	int a[100005];
	int val[100005];
	int pre[100005];
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pre[0]=pre[1]=0;
	for(int i  =2;i<n;i++){
		val[i]=a[i+1]-a[i-1]-2;
		pre[i]=pre[i-1]+val[i];
	}
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(l==r){
			printf("%d\n",k-1);
			continue;
		}
		int ans=pre[r-1]-pre[l];
		//	printf("%d\n",ans);
		ans+=a[l+1]-2;
		ans+=k-a[r-1]-1;
		printf("%d\n",ans);
	}
}
int main(){
	int t=1;//000000;
//    scanf("%d",&t);
    while(t--)solve();
}