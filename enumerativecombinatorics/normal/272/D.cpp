#include<stdio.h>
#include<algorithm>
using namespace std;
int b[100000];
int c[100000];
int e[200000];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++)scanf("%d",c+i);
	int d;
	scanf("%d",&d);
	long long ret=1;
	int div=0;
	for(int i=0;i<a;i++){
		if(b[i]==c[i])div++;
		e[i*2]=b[i];
		e[i*2+1]=c[i];
	}
	std::sort(e,e+a*2);
	e[a*2]=1999999999;
	int last=e[0];
	int ren=1;
	for(int i=1;i<a*2+1;i++){
		if(last!=e[i]){
			for(int j=1;j<=ren;j++){
				int t=j;
				while(div>0&&t%2==0){
					t/=2;
					div--;
				}
				ret=ret*t%d;
			}
			ren=1;
			last=e[i];
		}else ren++;
	}
	printf("%I64d\n",ret);
}