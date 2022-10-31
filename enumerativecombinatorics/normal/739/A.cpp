#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int ans=9999999;
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);
		ans=min(ans,q-p+1);
	}
	printf("%d\n",ans);
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",i%ans);
	}
	printf("\n");
}