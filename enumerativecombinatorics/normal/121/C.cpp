#include<stdio.h>
#include<algorithm>
using namespace std;
int fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int perm[13];
int used[13];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<13&&b>fact[a]){
		printf("-1\n");
		return 0;
	}
	int c=max(1,a-12);
	int ret=0;
	for(int i=1;i<=9;i++){
		for(int j=0;j<(1<<i);j++){
			int now=0;
			for(int k=0;k<i;k++){
				now*=10;
				if(j&(1<<k))now+=4;
				else now+=7;
			}
			if(now<c)ret++;
		}
	}
	int p=min(13,a);
	b--;
	for(int i=0;i<p;i++){
		int d=b/fact[p-i-1];
	//	printf("%d\n",d);
	//	fflush(stdout);
		b%=fact[p-i-1];
		int at=0;
		int e=d+1;
		while(1){
			if(!used[at])e--;
			if(e==0)break;
			at++;
		}
		used[at]=1;
		perm[i]=at;
	}
	for(int i=0;i<p;i++){
			int k=c+i;
			bool ok=true;
			while(k){
				if(k%10!=4&&k%10!=7)ok=false;
				k/=10;
			}
			k=c+perm[i];
			while(k){
				if(k%10!=4&&k%10!=7)ok=false;
				k/=10;
			}
			if(ok)ret++;
	}
	printf("%d\n",ret);
}