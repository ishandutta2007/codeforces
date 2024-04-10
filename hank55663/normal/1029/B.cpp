#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#define N
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int l=0;
	int ans=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]*2){
			ans=max(ans,i-l);
			l=i;
		}
	}
	ans=max(ans,n-l);
	printf("%d\n",ans);
}
/*
   s       20006
 qqqqqq  0~10000
bbbbbbbb  10001 20000
  5 5 5    20001 20005
     t    20007





*/