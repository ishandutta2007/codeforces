#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int,int> e[1000];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		int b,c;scanf("%d%d",&b,&c);
		e[i]=make_pair(b,c);
	}std::sort(e,e+a);
	int ret2=0;
	int now=0;
	int R=0;
	for(int i=0;i<a;i++){
		now-=(e[i].first-R);
		R=e[i].first;
		if(now<0)now=0;
		now+=e[i].second;
		ret2=max(ret2,now);
	}
	printf("%d %d\n",R+now,ret2);
}