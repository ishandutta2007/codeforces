#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
//#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int count[8]={0,0,1,7,4,5,6,7};
int main(){
	int n;
	scanf("%d",&n);
	if(n%2==1){
		printf("7");
		n-=3;
	}
	while(n){
		printf("1");
		n-=2;
	}
	printf("\n");
}/**/
/*
Y  * (5y-4)(y+1)*/