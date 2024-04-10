#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(m*2==k){
		rep(i,1,k)printf("%d",(i+1)&1);
		rep(i,1,n-m)printf("0");
	}else{
		rep(i,1,k)printf("%d",i&1);
		if(k&1){
			rep(i,1,m-k+k/2)printf("1");
			rep(i,1,n-k/2)printf("0");
		}else{
			rep(i,1,n-k/2)printf("0");
			rep(i,1,m-k+k/2)printf("1");
		}
	}
}