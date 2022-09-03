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
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int c2=0,c3=0;
		while(n%2==0){
			c2++;
			n/=2;
		}
		while(n%3==0){
			c3++;
			n/=3;
		}
		if(n!=1){
			printf("-1\n");
		}
		else{
			if(c3<c2){
				printf("-1\n");
			}
			else{
				printf("%d\n",c3+c3-c2);
			}
		}
	}
	return 0;
}