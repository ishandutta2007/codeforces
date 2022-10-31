#include<stdio.h>
#include<algorithm>
using namespace std;
int d[100000];
int e[100000];
int z[200000];
int A[200000];
int B[200000];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		scanf("%d",d+i);
		z[i]=d[i];
	}
	for(int i=0;i<b;i++){
		scanf("%d",e+i);
		z[a+i]=e[i];
	}
	std::sort(z,z+a+b);
	for(int i=0;i<a;i++){
		A[lower_bound(z,z+a+b,d[i])-z]++;
	}
	for(int i=0;i<b;i++){
		B[lower_bound(z,z+a+b,e[i])-z]++;
	}
	bool ok=false;
	int aa=0;
	int bb=0;
	for(int i=199999;i>=0;i--){
		aa+=A[i];
		bb+=B[i];
		if(aa>bb)ok=true;
	}
	if(ok)printf("YES\n");
	else printf("NO\n");
}