#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int T;
char a[9][10];
void add(char&x){x=(x-48)%9+49;}
int main(){
	for(scanf("%d",&T);T--;){
		FOR(i,0,8)scanf("%s",a[i]);
		FOR(i,0,8)add(a[i][i%3*3+i/3]);
		FOR(i,0,8)printf("%s\n",a[i]);
	}
}