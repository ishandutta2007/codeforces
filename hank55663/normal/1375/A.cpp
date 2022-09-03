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
		int a[100];
		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]);
			if(i&1)printf("%d ",-abs(a[i]));
			else printf("%d ",abs(a[i]));
		}
		printf("\n");
	}
	return 0;
}