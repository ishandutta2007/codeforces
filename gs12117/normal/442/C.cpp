#include<stdio.h>
#include<algorithm>
int n;
int a[500100];
int b[500100];
int p;
long long int ans;
int mmin(int x,int y){
	if(x<y)return x;
	return y;
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		while(p>=2&&b[p-2]>=b[p-1]&&a[i]>=b[p-1]){
			ans+=mmin(b[p-2],a[i]);
			p--;
		}
		b[p]=a[i];
		p++;
	}
	std::sort(b,b+p);
	for(i=0;i<p-2;i++){
		ans+=b[i];
	}
	printf("%I64d",ans);
}