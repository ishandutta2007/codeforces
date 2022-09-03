#include <bits/stdc++.h>
#define ll long long
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int llast=-1;
	int last=-1;
	int sum=0;
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x==1&&last==1){
			printf("Infinite\n");
			return 0;
		}
		else if((x==2||x==3)&&(last==2||last==3)){
			printf("Infinite\n");
			return 0;
		}
		else if(i!=0){
			if(last==2||x==2)
			sum+=3;
			else
			sum+=4;
		}
		if(llast==3&&last==1&&x==2)
		sum--;
		llast=last;
		last=x;
	}
	printf("Finite\n");
	printf("%d\n",sum);
}