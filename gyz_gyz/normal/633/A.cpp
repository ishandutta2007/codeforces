#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1000
using namespace std;
int x,y,z;
int main(){
	scanf("%d%d%d",&x,&y,&z);
	rep(i,0,z){
		int a=z-i*x;
		if(a>=0&&a%y==0){
			printf("Yes\n");return 0;
		}
	}
	printf("No\n");
}