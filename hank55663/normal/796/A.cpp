//#include<stdio.h>
//#include<stdlib.h>
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
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a[1005];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int ans=1e9;
	for(int i=1;i<=n;i++){
		if(a[i]!=0&&a[i]<=k)
		ans=min(ans,abs(i-m)*10);
	}
	printf("%d\n",ans);
}