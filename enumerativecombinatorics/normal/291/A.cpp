#include<stdio.h>
#include<algorithm>
using namespace std;
int t[1000];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",t+i);
	}
	bool ok=true;
	std::sort(t,t+a);
	for(int i=0;i<a-2;i++){
		if(t[i]&&t[i]==t[i+1]&&t[i+1]==t[i+2])ok=false;
	}
	if(!ok){
		printf("-1\n");
		return 0;
	}
	int ret=0;
	for(int i=0;i<a-1;i++)if(t[i]&&t[i]==t[i+1])ret++;
	printf("%d\n",ret);
}