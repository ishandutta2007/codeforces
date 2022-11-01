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
int UF[410000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int A[110000];
int B[110000];
int ans[410000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<4*a;i++)UF[i]=-1;
	int F=a*2;
	for(int i=0;i<a;i++){
		UNION(i*2,i*2+1+F);
		UNION(i*2+F,i*2+1);
	}
	for(int i=0;i<a;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		A[i]=p;B[i]=q;
		UNION(p,q+F);
		UNION(q,p+F);
	}
	for(int i=0;i<4*a;i++)ans[i]=-1;
	for(int i=0;i<a;i++){
		int f=ans[FIND(A[i])];
		if(f<0){
			ans[FIND(A[i])]=0;
			ans[FIND(A[i]+F)]=1;
			f=0;
		}
		printf("%d %d\n",f+1,(!f)+1);
	}
}