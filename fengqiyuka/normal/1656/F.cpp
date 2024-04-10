#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N];

bool cmp(int n1,int n2) {return (n1<n2);}
ll mymax(ll x,ll y) {return (x>y?x:y);}

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		sort(a+1,a+n+1,cmp);
		
		ll Sum=0;
		for(int i=1;i<=n;i++) Sum+=a[i];
		
		bool pd=false;
		if(Sum+(ll)a[1]*(n-2)<=0&&Sum+(ll)a[n]*(n-2)>=0) pd=true;
		if(!pd){
			printf("INF\n");
			continue;
		}
		
		ll Sum1=0,Sum2=0;
		for(int i=2;i<=n;i++) Sum2=Sum2+(ll)a[i]*a[1],Sum1=Sum1+a[i]+a[1];
		ll Ans=-1e18;
		Ans=mymax(Ans,Sum2+Sum1*(-a[1]));
		Ans=mymax(Ans,Sum2+Sum1*(-a[2]));
		for(int i=2;i<n;i++){
			Sum2=Sum2-(ll)a[i]*a[1]+(ll)a[i]*a[n];
			Sum1=Sum1-a[1]+a[n];
			Ans=mymax(Ans,Sum2+Sum1*(-a[i]));
			Ans=mymax(Ans,Sum2+Sum1*(-a[i+1]));
		}
		printf("%lld\n",Ans);
	}
	
	
	return 0;
}