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
pii vis[5000005];
bool solve(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<i;j++){
			if(vis[a[i]+a[j]].x==0){
				vis[a[i]+a[j]]=mp(i,j);
			}
			else if(vis[a[i]+a[j]].x!=i&&vis[a[i]+a[j]].x!=j&&vis[a[i]+a[j]].y!=i&&vis[a[i]+a[j]].y!=j){
				printf("YES\n");
				printf("%d %d %d %d\n",i,j,vis[a[i]+a[j]].x,vis[a[i]+a[j]].y);
				return true;
			}
		}
	}
	printf("NO\n");
}
int main(){
	int t=1;
   
	while(t--)solve();
}