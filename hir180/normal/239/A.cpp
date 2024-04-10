#include<cstdio>
#include <algorithm>
using namespace std;
int main(){
	long long a,b,c;
	bool f=0;
	scanf("%lld %lld %lld",&a,&b,&c);
	for(long long i=1;i<=c/b;i++){
		if(i*b>a){
			if(!f){
			printf("%d",i*b-a);
			f=1;
			}else{
			printf(" %d",i*b-a);
                        }
		}
	}
		if(!f){
			printf("-1");
		}
	printf("\n");
	return 0;
}