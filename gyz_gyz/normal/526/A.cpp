#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
char c[500];int n;
int main(){
	scanf("%d",&n);scanf("%s",c);
	rep(i,0,n-1)rep(j,1,n/4)
		if(c[i]=='*'&&c[i+j]=='*'&&c[i+j*2]=='*'&&c[i+j*3]=='*'&&c[i+j*4]=='*'){
			printf("yes\n");return 0;
		}
	printf("no\n");
}