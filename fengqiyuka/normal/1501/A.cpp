#include<cstdio>
#include<cstring>
using namespace std;
const int N=110;
int a[N],b[N],ti[N];
int mymax(int x,int y) {return x>y?x:y;}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		for(int i=1;i<=n;i++) scanf("%d",&ti[i]);
		int Sum=0;
		b[0]=0;
		for(int i=1;i<=n;i++){
			Sum=Sum+a[i]-b[i-1]+ti[i];
			if(i==n) break;
			Sum=mymax(Sum+(b[i]-a[i]+1)/2,b[i]);
		}
		printf("%d\n",Sum);
	}
	return 0;
}