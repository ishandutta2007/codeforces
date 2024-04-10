#include<stdio.h>
int n,m,p;
int a[100100];
int opr[100100][3];
int utime[100100];
long long int adelta[100100];
int main(){
	int i,ta,tb;
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&opr[i][0],&opr[i][1],&opr[i][2]);
	}
	for(i=0;i<p;i++){
		scanf("%d%d",&ta,&tb);
		utime[ta-1]++;
		utime[tb]--;
	}
	for(i=0;i<m;i++){
		adelta[opr[i][0]-1]+=(long long int)utime[i]*opr[i][2];
		adelta[opr[i][1]]-=(long long int)utime[i]*opr[i][2];
		utime[i+1]+=utime[i];
	}
	for(i=0;i<n;i++){
		printf("%I64d ",a[i]+adelta[i]);
		adelta[i+1]+=adelta[i];
	}
}