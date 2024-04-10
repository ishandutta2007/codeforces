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
	int n,k;
//	n=rand()%1000;
//	printf("%d\n",n);
	scanf("%d %d",&n,&k);
	n-=(k-3);
	for(int i = 0;i<k-3;i++){
		printf("1 ");
	}
	if(n%2==1){
		printf("1 %d %d\n",n/2,n/2);
	}
	else{
		for(int i = 2;;i+=2){
			int a=(n-i)/2;
			if(a*1ll*i/__gcd(a,i)<=n/2){
				printf("%d %d %d\n",i,a,a);
				return true;
			}
		}
	}
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}