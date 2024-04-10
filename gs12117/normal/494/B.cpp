#include<stdio.h>
int an,bn;
char a[100100];
char b[100100];
int ff[100100];
int kmp[100100];
int mod=1000000007;
long long int psum[100100];
long long int pdsum[100100];
int main(){
	int i,j;
	scanf("%s%s",a,b);
	for(an=0;a[an];an++);
	for(bn=0;b[bn];bn++);
	ff[0]=-1;
	j=0;
	for(i=1;i<bn;i++){
		while(j>=0&&b[i]!=b[j])j=ff[j];
		j++;
		ff[i+1]=j;
	}
	j=0;
	for(i=0;i<an;i++){
		while(j>=0&&a[i]!=b[j])j=ff[j];
		j++;
		kmp[i]=j;
	}
	psum[0]=1;
	psum[1]=1;
	pdsum[0]=1;
	pdsum[1]=1;
	j=-1;
	for(i=0;i<an;i++){
		if(kmp[i]==bn)j=i+1-bn;
		psum[i+1]+=pdsum[j];
		psum[i+1]%=mod;
		psum[i+2]=psum[i+1];
		pdsum[i+1]+=psum[i+1];
		pdsum[i+1]%=mod;
		pdsum[i+2]=pdsum[i+1];
	}
	printf("%I64d",(psum[an]+mod-1)%mod);
}