#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*('')*/
int main(){
	int n,ans=0,sum=0,s=0,now=0;
	int x[101],res[101];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		if(x[i]<0){
			sum++;
		}
	}
	for(int i=0;i<n;i++){
		if(x[i]<0){
			s++;
		}
		ans++;
		if(s==2){
			res[now]=ans;
			ans=0;
			s=0;
			now++;
		}
	}
	if(s==1){
		int y=n;
		for(int i=0;i<now;i++){
			y-=res[i];
		}
		res[now]=y;
		now++;
	}else if(s==0){
		if(now!=0){
		res[now-1]+=ans;
		}else{
			res[0]=n;
		}
	}
	printf("%d\n",max(1,(sum+1)/2));
	printf("%d",res[0]);
	for(int i=1;i<(sum+1)/2;i++){
		printf(" %d",res[i]);
	}
	printf("\n");
	scanf("\n");
	return 0;
}