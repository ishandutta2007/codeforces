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
int p[210000];
int q[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%d",p+i,q+i);
	}
	int tt=0;
	for(int i=0;i<a;i++)if(q[i]==2)tt++;
	if(!tt){
		printf("Infinity\n");return 0;
	}
	int L=-999999999;
	int R=999999999;
	for(int i=0;i<a;i++){
		if(q[i]==1){
			L=max(L,1900);
		}else{
			R=min(R,1899);
		}
		L+=p[i];
		R+=p[i];
	//	printf("%d %d\n",L,R);
	}
	if(L>R){
		printf("Impossible\n");return 0;
	}
	printf("%d\n",R);
}