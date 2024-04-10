#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define EPS 1e-11
//#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define sqr(x) ((x)*(x))
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long LL;
int main(){
	LL n,k;
	scanf("%I64d %I64d",&n,&k);
	LL a=n/2/(k+1),b=k*a,c=n-a-b;
	printf("%I64d %I64d %I64d\n",a,b,c);
}
//Axyz=xy+yz+zx
// Y k  
// S k+y|k+y+a
//P k+p/k+p+b
// S k+p+s+0~2=k+y+0~1
// 3*k+y+p+a+b=12+j