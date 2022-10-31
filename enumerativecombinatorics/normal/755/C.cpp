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
int b[11000];
int UF[11000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",b+i);b[i]--;
	}
	for(int i=0;i<a;i++)UF[i]=-1;
	for(int i=0;i<a;i++){
		UNION(b[i],i);
	}
	int ret=0;
	for(int i=0;i<a;i++)if(UF[i]<0)ret++;
	printf("%d\n",ret);
}