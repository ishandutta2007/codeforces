#include<cstdio>
#include<algorithm>
using namespace std;
int a[110],n,m;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+m);
		if(a[0]==a[m-1])printf("0\n");
		else printf("%d\n",m-(upper_bound(a,a+m,a[0])-a));
	}
	return 0;
}