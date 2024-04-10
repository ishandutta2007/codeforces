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
	LL val[200005];
	LL a[200005];
	for(int i = 0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	val[0]=a[0];
	int Mini=n;
	for(int i = 1;i<n;i++){
		val[i]=a[i]-val[i-1];
	}
	for(int i = 0;i<n;i++){
		if(val[i]<0){
			Mini=i;
			break;
		}
	}
	for(int i = 0;i<n;i++){
	//	printf("%lld ",val[i]);
	}
	//printf("\n");
	if(val[n-1]==0&&Mini==n){
		printf("YES\n");
		return true;
	}
	LL oddMax=1e18,oddMin=1e18,evenMax=-1e18,evenMin=1e18;
	for(int i = n-1;i>Mini;i--){
		if(i%2)oddMax=max(oddMax,val[i]),oddMin=min(oddMin,val[i]);
		else evenMax=max(evenMax,val[i]),evenMin=min(evenMin,val[i]);
	}
	for(int i = Mini;i>=0;i--){
	//	printf("%d\n",i);
		if(i==n-1)continue;
		if(i%2){
			//	printf("%lld %lld\n",oddMin-2*(a[i]-a[i+1]),evenMin-2*(a[i+1]-a[i]));
			if(val[i]-a[i]+a[i+1]>=0&&oddMin-2*(a[i]-a[i+1])>=0&&evenMin-2*(a[i+1]-a[i])>=0){
			
				if((n-1)%2==1){
					if(val[n-1]-2*(a[i]-a[i+1])==0){
						printf("YES\n");
						return true;
					}
				}
				else{
					if(val[n-1]-2*(a[i+1]-a[i])==0){
						printf("YES\n");
						return true;
					}
				}
			}
		}
		else{
		//	printf("%lld %lld\n",oddMin-2*(a[i+1]-a[i]),evenMin-2*(a[i]-a[i+1]));
			if(val[i]-a[i]+a[i+1]>=0&&oddMin-2*(a[i+1]-a[i])>=0&&evenMin-2*(a[i]-a[i+1])>=0){
				
				if((n-1)%2==1){
					if(val[n-1]-2*(a[i+1]-a[i])==0){
						printf("YES\n");
						return true;
					}
				}
				else{
					if(val[n-1]-2*(a[i]-a[i+1])==0){
						printf("YES\n");
						return true;
					}
				}
			}
		}
		if(i%2)oddMax=max(oddMax,val[i]),oddMin=min(oddMin,val[i]);
		else evenMax=max(evenMax,val[i]),evenMin=min(evenMin,val[i]);
	}
	printf("NO\n");
    return true;
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/