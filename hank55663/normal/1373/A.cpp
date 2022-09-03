#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		LL a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(c<=a){
			printf("-1");
		}
		else{
			printf("1");
		}
		if(b*a<=c){
			printf(" -1\n");
		}
		else{
			printf(" %lld\n",b);
		}
	}
	return 0;
}