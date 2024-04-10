#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

int main() {
	LL a[4];
	scanf("%lld %lld %lld",&a[1],&a[2],&a[3]);
	printf("First\n");
	int n=1e9+7;
	printf("%d\n",n);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	a[x]+=n;
	LL b[4];
	for(int i = 1;i<=3;i++)b[i]=a[i];
	sort(b+1,b+4);
	printf("%lld\n",(b[3]-b[2])*2+b[2]-b[1]);
	fflush(stdout);
	//int x;
	scanf("%d",&x);
	if(x==0)return 0;
	a[x]+=(b[3]-b[2])*2+b[2]-b[1];
	for(int i = 1;i<=3;i++)b[i]=a[i];
	sort(b+1,b+4);
	assert(b[3]-b[2]==b[2]-b[1]);
	printf("%lld\n",b[3]-b[2]);
	fflush(stdout);
	//int x;
	scanf("%d",&x);
	return 0;
}