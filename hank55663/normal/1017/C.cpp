#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int Min=1e9,minx,miny;
	for(int i=1;i<=n;i++){
		int x=i,y=n/i;
		if(n%i!=0)
		y++;
		if(x+y<Min){
			Min=x+y;
			minx=x;
			miny=y;
		}
	}
	int ans[100005];
	for(int i=0;i<n;i++)
		ans[i]=i+1;
	for(int i=0;i<n;i+=minx){
		reverse(ans+i,ans+min(i+minx,n));
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
}