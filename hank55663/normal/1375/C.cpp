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
	int a[300005];
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]);
		}
		/*int Max=0,Min=1e9;
		int ok=1;
		for(int i = 0;i<n-1;i++){
			Min=min(Min,a[i]);
			Max=max(Max,a[i]);
			if(i==Max-Min&&Max==n)ok=0;
		}*/
		if(a[0]<a[n-1])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}