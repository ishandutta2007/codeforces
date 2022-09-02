#include <cstdio>
#include <algorithm>
using namespace std;
int num[100005],n,sum[100005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		sum[i]=num[i];
	}
	int g=0;
	bool a=false,b=false;
	sort(sum,sum+n);
	for(int i=0;i<n-1;i++){
		if(sum[i]!=sum[i+1]){
			g++;
		}
	}
	if(g==0){
		printf("-1\n");
		return 0;
	}
	if(g==1 && n<=2){
		printf("-1\n");
		return 0;
	}
	if(g==1 && n==3 && num[0]==num[2] && num[0]!=num[1]){
		printf("-1\n");
		return 0;
	}
	int aa=0,bb=0;
	for(int i=0;i<n-1;i++){
		if(num[i]>num[i+1]){
			a=true;
			aa++;
		}else if(num[i]<num[i+1]){
			b=true;
			bb++;
		}
	}
	if(!a){
		for(int i=0;i<n-1;i++){
			if(num[i]!=num[i+1]){
				printf("%d %d\n",i+1,i+2);
				return 0;
			}
		}
	}else if(!b){
		for(int i=0;i<n-1;i++){
			if(num[i]!=num[i+1]){
				printf("%d %d\n",i+1,i+2);
				return 0;
			}
		}
	}else{
		int ans1,ans2;
		if(aa>1){
	for(int i=0;i<n-1;i++){
		if(num[i]>num[i+1]){
			printf("%d %d\n",i+1,i+2);
			return 0;
		}
	}
		}else if(bb>1){
	for(int i=0;i<n-1;i++){
		if(num[i]<num[i+1]){
			printf("%d %d\n",i+1,i+2);
			return 0;
		}
	}
	}else{
		int re=0;
		int r,rr;
	for(int i=0;i<n-1;i++){
		if(num[i]!=num[i+1]){
			r=i+1; rr=i+2;
			while(1){
				i++;re++;
				if(num[i]!=num[i+1]){
					break;
				}
			}
			if(re!=1){
				printf("%d %d\n",r,rr);
				return 0;
			}else{
				if(r!=1){
				printf("%d %d\n",r,rr);
				return 0;
				}else{
					if(n==3){
						printf("1 %d\n",n);
					}else{
						printf("2 3\n");
					}
					return 0;
				}
			}
		}
		}
	}
	}
}