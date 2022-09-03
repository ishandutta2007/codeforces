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
	int a[50];
	for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i = 1;i<n;i++){
		int x=a[i],y=a[i+1];
		if(x>y)swap(x,y);
		while(x*2<y){
			x*=2;
			ans++;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}