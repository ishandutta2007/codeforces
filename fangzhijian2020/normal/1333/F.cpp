#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[500005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){a[i]=1;
		for(int j=2;j*j<=i;++j){
			if(i%j==0){a[i]=max(a[i],i/j);}
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i)printf("%d ",a[i]);
	return 0;
}