#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int p[1100];
int UF[1100];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;
	UF[a]+=UF[b];UF[b]=a;
}
int has[1100];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<c;i++){
		scanf("%d",p+i);
		p[i]--;
	}
	for(int i=0;i<a;i++)UF[i]=-1;
	for(int i=0;i<b;i++){
		int s,t;scanf("%d%d",&s,&t);s--;t--;
		UNION(s,t);
	}
	for(int i=0;i<c;i++)has[FIND(p[i])]=1;
	int ms=0;
	int ret=-b;
	for(int i=0;i<a;i++){
		if(UF[i]<0){
			int sz=-UF[i];
			ret+=sz*(sz-1)/2;
			if(has[i]){
				ms=max(ms,sz);
			}
		}
	}
	//printf("%d\n",ret);
	for(int i=0;i<a;i++){
		if(UF[i]<0&&has[i]==0){
			ret+=ms*(-UF[i]);
			ms+=-UF[i];
		}
	}
	printf("%d\n",ret);
}