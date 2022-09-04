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
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){	
	LL n,s;
	scanf("%I64d %I64d",&n,&s);
	LL ans=n-s+1;
	for(LL i=s;i<s+5000&&i<=n;i++){
		LL k=i;
		LL sum=0;
		while(k){
			sum+=k%10;k/=10; 
		}
		if(i-sum<s)
		ans--;
	}
	if(s>n)
	printf("0");
	else
	printf("%I64d\n",ans);
}