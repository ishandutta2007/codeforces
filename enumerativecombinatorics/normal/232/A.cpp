#include<stdio.h>
#include<algorithm>
using namespace std;
char out[100][101];
int main(){
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			out[i][j]='0';
	int a;
	scanf("%d",&a);
	int n=3;
	while(n*(n-1)*(n-2)/6<a)n++;
	int d=n*(n-1)*(n-2)/6-a;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			out[i][j]=(i!=j?'1':'0');
	int at=0;
	while(d>0){
		out[at][at+1]=out[at+1][at]='0';
		at+=2;
		d-=n-2;
	}
	d=-d;
	if(d){
		int m=3;
		while(m*(m-1)*(m-2)/6<d)m++;
		int e=m*(m-1)*(m-2)/6-d;
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				out[n+i][n+j]=(i!=j?'1':'0');
		at=0;
		while(e>0){
			out[n+at][n+at+1]=out[n+at+1][n+at]='0';
			at+=2;
			e-=m-2;
		}
		e=-e;
		int S=n+m;
		switch(e){
			case 3:
				out[S+1][S+4]=out[S+2][S+4]=out[S+4][S+2]=out[S+4][S+1]='1';
			case 2:
				out[S][S+3]=out[S+1][S+3]=out[S+3][S]=out[S+3][S+1]='1';
			case 1:
				out[S][S+1]=out[S+1][S]=out[S+2][S]=out[S][S+2]=out[S+1][S+2]=out[S+2][S+1]='1';
				break;
			case 7:
				out[S+2][S+4]=out[S+4][S+2]='1';
			case 5:
				out[S][S+4]=out[S+1][S+4]=out[S+4][S]=out[S+4][S+1]='1';
			case 4:
				out[S][S+3]=out[S+1][S+3]=out[S+3][S]=out[S+3][S+1]=out[S+2][S+3]=out[S+3][S+2]='1';
				out[S][S+1]=out[S+1][S]=out[S+2][S]=out[S][S+2]=out[S+1][S+2]=out[S+2][S+1]='1';
				break;
			case 6:
				out[S][S+1]=out[S][S+2]=out[S][S+3]=out[S][S+4]=out[S+1][S]=out[S+2][S]=out[S+3][S]=out[S+4][S]='1';
				out[S+2][S+1]=out[S+1][S+2]=out[S+2][S+3]=out[S+3][S+4]=out[S+1][S+3]=out[S+3][S+1]=out[S+3][S+2]=out[S+4][S+3]='1';
				break;
		}
	}
	printf("100\n");
	for(int i=0;i<100;i++)printf("%s\n",out[i]);
}