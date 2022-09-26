#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=(1<<18)-1;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int k,a[233][233];
int main(){
	k=read();
	printf("%d %d\n",2,3);
	a[1][1]=a[2][2]=inf;
	a[2][1]=inf-k;
	a[1][2]=a[2][3]=k;
	for(int i=1;i<=2;++i){
		for(int j=1;j<=3;++j){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}