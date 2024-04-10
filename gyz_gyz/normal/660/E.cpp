#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mo 1000000007
#define LL long long
using namespace std;
int n,m;LL ans;
LL pw(int x,int y){
	if(!y)return 1;LL r=pw(x,y/2);
	r=r*r%mo;if(y&1)r=r*x%mo;return r;
}
int main(){
	scanf("%d%d",&n,&m);ans=pw(m,n);
	rep(i,0,n-1)ans=(ans+pw(m,i)*m%mo*pw(m*2-1,n-i-1))%mo;
	printf("%I64d\n",ans);
}