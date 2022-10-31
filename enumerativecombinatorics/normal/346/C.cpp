#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int b[100000];
int bfs[1000001];
int use[1000001];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	std::sort(b,b+a);
	int c,d;
	scanf("%d%d",&c,&d);
	int n=c-d+1;
	for(int i=0;i<n;i++)use[i]=i+1+d;
	for(int i=0;i<a;i++){
		if(i&&b[i]==b[i-1])continue;
		int t=(d%b[i]==0)?d:(d+b[i]-d%b[i]);
		while(t<=c){
			use[t-d]=max(use[t-d],t+b[i]-1);
			t+=b[i];
		}
	}
	for(int i=1;i<n;i++){
		use[i]=max(use[i],use[i-1]);
	//	printf("%d: %d\n",i+d,use[i]);
	}
	int at=d;
	int ret=0;
	while(at<c){
		at=use[at-d];
//		printf("%d\n",at);
		ret++;
	}
	printf("%d\n",ret);
}