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
	int a,b;
	scanf("%d %d",&a,&b);
	LL sum=0;
	for(int i = 1;i<=a;){
		int val=a/i;
		int l=i,r=a/val;
		sum+=min(max(a/i-i-1,0),max(b-i,0))*1ll*(r-l+1);
		i=r+1;
	}
	printf("%lld\n",sum);
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}