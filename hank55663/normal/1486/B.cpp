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
	int n;
	scanf("%d",&n);
	int x[1005],y[1005];
	for(int i = 0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	if(n%2==1){
		printf("1\n");
		return true;
	}
	sort(x,x+n);
	sort(y,y+n);
	printf("%lld\n",(x[n/2]-x[n/2-1]+1)*1ll*(y[n/2]-y[n/2-1]+1));
	return true;
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}