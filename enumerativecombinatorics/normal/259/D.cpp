#include<stdio.h>
#include<algorithm>
using namespace std;
int b[6];
int c[5];
int r[20];
int perm[14];
int s[10];
int main(){
	int a;
	scanf("%d",&a);
	int t=a/100000;
	for(int i=0;i<100000;i++){
		int d=i;
		int e=0;
		while(d){
			if(d%10==4||d%10==7)e++;
			d/=10;
		}
		b[e]++;
	}
	for(int i=0;i<t;i++){
		int d=i;
		int e=0;
		while(d){
			if(d%10==4||d%10==7)e++;
			d/=10;
		}
		c[e]++;
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			r[i+j]+=b[i]*c[j];
		}
	}
	for(int i=t*100000;i<=a;i++){
		int d=i;
		int e=0;
		while(d){
			if(d%10==4||d%10==7)e++;
			d/=10;
		}
		r[e]++;
	}
	r[0]--;
	int v=0;
	int mod=1000000007;
	long long ret=0;
	for(int i=8;i<14;i++){
		perm[i]=1;
	}
	do{
		long long now=1;
		int n=0;
		int m=0;
		for(int i=0;i<10;i++)s[i]=0;
		int x=0;
		for(int i=0;i<14;i++){
			if(perm[i]){
				now=now*(r[n]-s[n])%mod;
				s[n]++;
				n=0;
				x++;
				if(x==6)break;
			}else {n++;m++;}
		}
		int K=0;
		for(int i=m+1;i<10;i++)K+=r[i];
		now=now*K%mod;
		ret=(ret+now)%mod;
	}while(next_permutation(perm,perm+14));
	printf("%d\n",(int)ret);
}