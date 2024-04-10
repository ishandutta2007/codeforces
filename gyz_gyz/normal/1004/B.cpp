#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1048576
#define inf 1000000000
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n)printf("%d",i%2);
}