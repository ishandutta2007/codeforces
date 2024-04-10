#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('') */
int n,m,x,y,z,sum,k,now1=1,now2=2;
int q[31];
int ans[31][31];
bool f=false;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&q[i]);
		ans[i][1]=q[i];
	}
	for(int i=1;i<=n*k;i++){
		for(int j=1;j<=k;j++){
			if(q[j]==i){
				f=true;
			}
		}
		if(!f){
			ans[now1][now2]=i;
			now2++;
			if(now2>n){
				now1++;
				now2=2;
			}
		}
		f=false;
	}
	for(int i=1;i<=k;i++){
		printf("%d",ans[i][1]);
		for(int j=2;j<=n;j++){
			printf(" %d",ans[i][j]);
		}
		printf("\n");
	}
	scanf("%d",&ans);
	return 0;
}