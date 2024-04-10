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
	int n,m;
	scanf("%d",&n);
	int a[300005];
	LL sum=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int Min=1e9;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		printf("%lld\n",sum-a[x]);
	}
	//printf("%lld\n",sum-a[Min]);
}