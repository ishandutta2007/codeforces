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
#define index Index
using namespace std;
bool solve(){
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int w,bb;
	scanf("%d %d",&w,&bb);
	if((a+b)/2<w){
		printf("NO\n");
		return true;
	}
	if((n-a+n-b)/2<bb){
		printf("NO\n");
		return true ;
	}
	printf("YES\n");
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}