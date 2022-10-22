#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	int n,h;
	scanf("%d %d",&n,&h);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sort(a+1,a+1+i);
		if(i%2==1){
		
			int H=0;
			H+=a[1];
			for(int j=3;j<=i;j+=2){
				H+=a[j];
			}
			if(H>h){
				printf("%d\n",i-1);
				return 0;
			}
		}
		else{
			int H=0;
			for(int j=2;j<=i;j+=2){
				H+=a[j];
			}
			if(H>h){
				printf("%d\n",i-1);
				return 0;
			}
		}
	}
	printf("%d\n",n);
	return 0;
}