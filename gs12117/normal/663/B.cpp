#include<stdio.h>
#include<string.h>
int n;
char s[20];
int a[20];
long long int powt[15];
long long int rem[15];
long long int f(int len){
	if(len==1){
		if(a[0]==9)return 1989;
		return 1990+a[0];
	}
	long long int sy=f(len-1);
	while(1){
		sy+=powt[len-1];
		if(sy%powt[len]==rem[len-1]){
			return sy;
		}
	}
}
int main(){
	int i,j;
	powt[0]=1;
	for(i=0;i<16;i++)powt[i+1]=powt[i]*10;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		j=0;
		rem[0]=0;
		for(i=strlen(s)-1;i>3;i--){
			a[j]=s[i]-'0';
			rem[j]+=powt[j]*a[j];
			rem[j+1]=rem[j];
			j++;
		}
		printf("%I64d\n",f(j));
	}
	return 0;
}