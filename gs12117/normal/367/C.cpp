#include<stdio.h>
#include<algorithm>
int n,m;
int a[100100];
long long int ans;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%*d%d",&a[i]);
	}
	std::sort(a,a+m);
	for(i=0;i<m;i++){
		if(i%2==0){
			if(n<(i+1)*i/2+1)break;
		}
		else{
			if(n<(i+1)*(i+1)/2)break;
		}
	}
	for(i=m-i;i<m;i++){
		ans+=a[i];
	}
	printf("%I64d",ans);
}