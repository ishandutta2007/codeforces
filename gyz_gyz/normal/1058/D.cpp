#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 2000000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,k,x,y;
int gcd(int x,int y){
	if(!x)return y;return gcd(y%x,x);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	x=gcd(k,n);k/=x;x=n/x;
	y=gcd(k,m);k/=y;y=m/y;
	if(k>2){printf("NO");return 0;}printf("YES\n");
	if(k==2)printf("0 0\n%d 0\n0 %d\n",x,y);
	else if(x*2<=n)printf("0 0\n%d 0\n0 %d\n",x*2,y);
	else printf("0 0\n%d 0\n0 %d\n",x,y*2);
}