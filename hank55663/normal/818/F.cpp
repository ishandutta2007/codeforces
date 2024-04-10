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
	int t;
	scanf("%d",&t);
	while(t--){
		LL n;
		scanf("%I64d",&n);
		if(n==1){
			printf("0\n");
			continue;
		}
		LL Min=0,Max=n-1;
		while(Min+100<Max){
			LL mid1=(Min*2+Max)/3,mid2=(Min+Max*2)/3;
			LL sum1=mid1+min(mid1,(n-mid1)*(n-mid1-1)/2);
			LL sum2=mid2+min(mid2,(n-mid2)*(n-mid2-1)/2);
			if(sum2<sum1)Max=mid2;
			else Min=mid1;
		//	printf("%I64d %I64d %I64d %I64d\n",mid1,sum1,mid2,sum2);
		}
		LL ans=0;
		for(LL i=Min;i<=Max;i++){ 
		//	printf("%d %d\n",i,i+min(i,(n-i)*(n-i-1)/2));
			ans=max(ans,i+min(i,(n-i)*(n-i-1)/2));
		} 
		printf("%I64d\n",ans);
	}
	 
}
//Axyz=xy+yz+zx
// Y k  
// S k+y|k+y+a
//P k+p/k+p+b
// S k+p+s+0~2=k+y+0~1
// 3*k+y+p+a+b=12+j