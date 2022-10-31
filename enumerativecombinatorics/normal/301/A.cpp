#include<stdio.h>
#include<algorithm>
using namespace std;
int b[200];
int main(){
	int a;scanf("%d",&a);for(int i=0;i<2*a-1;i++)scanf("%d",b+i);
	std::sort(b,b+a*2-1);
	int ret=-9999999;
	for(int j=0;j<=a*2-1;j++){
		if(a%2==0&&j%2)continue;
		int now=0;
		for(int i=0;i<j;i++)now-=b[i];
		for(int i=j;i<a*2-1;i++)now+=b[i];
		ret=max(ret,now);
	}
	printf("%d\n",ret);
}