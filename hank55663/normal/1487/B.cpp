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
void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	if(n%2==0){
		printf("%d\n",(k-1)%n+1);
	}
	else{
		LL dis=((n-1)/2-(k-1)%((n-1)/2))*2;
		LL loca=n+1-((k-1)%n+1);
	//	printf("%lld\n",loca);
		printf("%d\n",(loca-dis+n-1)%n+1);
	}
}
int main(){
    int t=1;00000;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*

*/