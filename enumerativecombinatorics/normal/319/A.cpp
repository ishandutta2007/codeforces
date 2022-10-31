#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[128];
int main(){
	scanf("%s",str);
	int mod=1000000007;
	int n=strlen(str);
	int ret=0;
	for(int i=0;i<n;i++){
		if(str[i]=='1'){
			int now=1;
			for(int j=0;j<2*n-i-2;j++){
				now=now*2%mod;
			}
			ret=(ret+now)%mod;
		}
	}printf("%d\n",ret);
}