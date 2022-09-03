#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
int main(){
	LL n;
	scanf("%lld",&n);
	if(n==0){
		printf("0\n");
		return 0;
	}
	n++;
	if(n%2==0)
	printf("%lld\n",n/2);
	else
	printf("%lld\n",n);
}