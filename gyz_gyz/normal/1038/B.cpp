#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define n2 500000004
#define eps 1e-8
using namespace std;
int n,k,x;
int main(){
	scanf("%d",&n);
	if((!(n%4))||(n%4==3)){
		printf("Yes\n");
		printf("%d",n-n/2);
		rep(i,1,n-n/2)printf(" %d",i*2-1);
		printf("\n%d",n/2);
		rep(i,1,n/2)printf(" %d",i*2);return 0;
	}
	rep(i,3,n-1)if((i&1)&&((n%i==(i-1))||(!(n%i)))){
		x=i;break;
	}
	if(!x){printf("No");return 0;}
	printf("Yes\n");
	printf("%d",n/x);
	rep(i,1,n/x)printf(" %d",i*x);
	printf("\n%d",n-n/x);
	rep(i,1,n)if(i%x)printf(" %d",i);
}