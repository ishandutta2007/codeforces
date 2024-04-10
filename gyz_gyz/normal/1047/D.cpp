#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 1000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
ll n,m;
int main(){
	scanf("%I64d%I64d",&n,&m);
	if(n<m)swap(n,m);
	if(m==1){
		printf("%I64d",n/6*6+max(n%6-3,0ll)*2);return 0;
	}
	if((n==2)&&(m==2)){printf("0");return 0;}
	if((n==3)&&(m==2)){printf("4");return 0;}
	if((n==7)&&(m==2)){printf("12");return 0;}
	printf("%I64d",n*m/2*2);
}