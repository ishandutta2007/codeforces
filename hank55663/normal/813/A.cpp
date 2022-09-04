#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){	
	LL n;
	scanf("%lld",&n);
	LL a[100005];
	LL sum=0;
	for(int i=0;i<n;i++)
	scanf("%lld",&a[i]),sum+=a[i];
	LL m;
	scanf("%lld",&m);
	while(m--){
		LL l,r;
		scanf("%lld %lld",&l,&r);
		if(r>=sum){
			printf("%lld\n",max(sum,l));
			return 0;
		}
	}
	printf("-1\n");
}