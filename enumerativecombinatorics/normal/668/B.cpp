#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int ret[1100000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int p1=0;
	int p2=1;
	while(b--){
		int c;scanf("%d",&c);
		if(c==1){
			int d;scanf("%d",&d);
			p1+=d;
			p2+=d;
			if(p1<0)p1+=a;
			if(p2<0)p2+=a;
			if(p1>=a)p1-=a;
			if(p2>=a)p2-=a;
			
		}else{
			p1^=1;
			p2^=1;
		}
	}
	for(int i=0;i<a/2;i++){
		ret[(p1+i*2)%a]=i*2+1;
		ret[(p2+i*2)%a]=i*2+2;
	}
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",ret[i]);
	}
	printf("\n");
}