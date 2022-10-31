#include<stdio.h>
#include<algorithm>
using namespace std;
int prime[110000];
int aite[110000];
int use[110000];
int A[110000];
int B[110000];
int gcd(int a,int b){
	while(a){
		b%=a;
		int c=a;a=b;b=c;
	}return b;
}
int main(){
	int a;scanf("%d",&a);
	prime[0]=prime[1]=-1;
	for(int i=2;i<110000;i++){
		if(~prime[i]){
			prime[i]=1;
			for(int j=i+i;j<110000;j+=i)prime[j]=-1;
		}
	}
	use[1]=1;aite[1]=1;
	int rem=-1;
	for(int i=2;i<=a;i++){
		if(~prime[i]){
			;
		}else{
			if(i%2==0&&~prime[i/2]){
				use[i]=use[i/2]=1;
				aite[i]=i/2;
				aite[i/2]=i;
			}else if(!~rem){
				rem=i;
			}else{
				int at=-1;
				for(int j=2;j<i;j++){
					if(use[j]&&rem!=j){
						if(gcd(j,i)!=1&&gcd(aite[j],rem)!=1){
							use[i]=use[rem]=1;
							aite[i]=j;aite[rem]=aite[j];aite[aite[j]]=rem;aite[j]=i;
							rem=-1;
							at=j;
							break;
						}
						if(gcd(j,rem)!=1&&gcd(aite[j],i)!=1){
							use[i]=use[rem]=1;
							aite[i]=aite[j];aite[rem]=j;aite[aite[j]]=i;aite[j]=rem;
							rem=-1;
							at=j;
							break;
						}
					}
				}
			//	if(at==-1){
			//		printf("dame\n");return 0;
			//	}
			}
		}
	}
	int ret=0;
	for(int i=2;i<=a;i++){
		if(use[i]){
			A[ret]=i;
			B[ret]=aite[i];
			use[i]=use[aite[i]]=0;
			ret++;
		}
	}printf("%d\n",ret);
	for(int i=0;i<ret;i++)printf("%d %d\n",A[i],B[i]);
}