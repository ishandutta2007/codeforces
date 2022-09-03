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
	LL a[100005];
	LL tmp[100005];
	int arr[100005];
	arr[0]=n;
	for(int i = 1;i<=(n-2)/2;i++)arr[i]=i+1;
	arr[(n-2)/2+1]=1;
	int now=n/2+1;
	for(int i = (n-2)/2+2;i<n;i++)arr[i]=now++;
	//for(int i = 0;i<n;i++)printf("%d ",arr[i]);
//	printf("\n");
	for(int i = 0;i<n;i++)a[arr[i]]=arr[(i+1)%n];
	for(int i = 1;i<=n;i++)tmp[i]=a[i];

	vector<pii> v;
	LL ans=0;
	while(a[n]!=1)ans+=(a[n]-n)*(a[n]-n),v.pb(mp(a[n],n)),swap(a[a[n]],a[n]);
	while(a[1]!=n)ans+=(a[1]-1)*(a[1]-1),v.pb(mp(a[1],1)),swap(a[a[1]],a[1]);
	ans+=(a[1]-1)*(a[1]-1);
	v.pb(mp(a[1],1));
	swap(a[a[1]],a[1]);

	//for(int i = 1;i<n;i++)a[i]=i+1;
	//a[n]=1;
	//LL sum=0;
	
	//for(LL i = 1;i<n;i++) sum+=i*i;
	printf("%lld\n",ans);
	for(int i = 1;i<=n;i++){
		printf("%lld ",tmp[i]);
	}
	printf("\n");
	printf("%d\n",v.size());
	for(auto it:v)printf("%d %d\n",it.x,it.y);

//	for(int i = 1;i<=n;i++)printf("%d ",a[i]);
//	printf("\n");
	//printf("%d\n",n-1);
/*	LL sum2=0;
	while(a[n]!=n){
	//	printf("%d %d\n",a[n],n);
		sum2+=(a[n]-n)*1ll*(a[n]-n);
		swap(a[a[n]],a[n]);
	}
	printf("%lld\n",sum2);*/
	/*
	for(int i = n-1;i>=1;i--){
		printf("%d %d\n",a[i],i);
		swap(a[a[i]],a[i]);
	}*/
	//for(int i = 1;i<=n;i++)printf("%d ",a[i]);
	//printf("\n");
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