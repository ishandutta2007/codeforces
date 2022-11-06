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
#define N 3010
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,l,r,m,X,Y,x,y;
int main(){
	scanf("%d",&n);
	if((n/2)&1){printf("! -1\n");return 0;}
	printf("? 1\n");fflush(stdout);scanf("%d",&X);
	printf("? %d\n",n/2+1);fflush(stdout);scanf("%d",&Y);
	if(X==Y){printf("! 1\n");return 0;}
	l=2;r=n/2;m=(l+r)/2;
	for(;;m=(l+r)/2){
		printf("? %d\n",m);fflush(stdout);scanf("%d",&x);
		printf("? %d\n",n/2+m);fflush(stdout);scanf("%d",&y);
		if(x==y){printf("! %d\n",m);return 0;}
		if((x>y)!=(X>Y))r=m-1;else l=m+1;
	}
}