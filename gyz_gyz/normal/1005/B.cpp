#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1000000
using namespace std;
char a[N],b[N];
int n,m;
int main(){
	scanf("%s",a);while(a[n])n++;
	scanf("%s",b);while(b[m])m++;
	while((n>=0)&&(m>=0)&&(a[n]==b[m]))n--,m--;
	printf("%d\n",n+m+2);
}