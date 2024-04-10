#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define Rep(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
int n;long long a[1000001],ans,x;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);x=0;
	Rep(i,n,1){
		if(a[i]!=a[i+1]&&a[i]>a[i-1])a[i]--;
		if(a[i]==a[i+1]){
			if(!x)x=a[i];else{
				ans+=a[i]*x;x=0;
			}
			a[i]=0;
		}
	}
	printf("%I64d\n",ans);
}