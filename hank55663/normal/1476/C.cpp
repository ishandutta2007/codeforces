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
	LL c[100005];
	LL a[100005];
	LL b[100005];
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%lld",&c[i]);
		c[i]--;
	}
	for(int i = 0;i<n;i++)scanf("%lld",&a[i]);
	for(int i = 0;i<n;i++)scanf("%lld",&b[i]);
	for(int i = 0;i<n;i++){
		if(a[i]>b[i])swap(a[i],b[i]);
	}
	LL ans=0;
	LL sum=c[n-1]+2;
	for(int i = n-1;i>0;i--){
		//	printf("%lld\n",sum);
		ans=max(ans,sum+b[i]-a[i]);
		if(b[i]==a[i])sum=c[i-1]+2;
		else{
			sum=max(sum+c[i-1]-(b[i]-a[i])+2,c[i-1]+2);
		}
	
	}
	printf("%lld\n",ans);
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