#include<stdio.h>
char str[128];
int v[128][26];
int main(){
	int mod=1000000007;
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%s",str);
		for(int j=0;j<b;j++)v[j][str[j]-'A']++;
	}
	long long ret=1;
	for(int i=0;i<b;i++){
		int count=0;
		for(int j=0;j<26;j++)if(v[i][j])count++;
		ret=ret*count%mod;
	}
	printf("%d\n",ret);
}