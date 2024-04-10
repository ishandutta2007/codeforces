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
	int n,m;
	scanf("%d %d",&n,&m);
	int ans[105];
	int num[105];
	MEM(ans);
	MEM(num);
	int last;
	scanf("%d",&last);
	for(int i=1;i<m;i++){
		int a;
		scanf("%d",&a);
		if(ans[last]==0){
			ans[last]=(a-last+n-1)%n+1;
			if(num[ans[last]]){
				printf("-1\n");
				return 0;
			}
			num[ans[last]]=1;
		}
		else if(ans[last]!=(a-last+n-1)%n+1){
			printf("-1\n");
			return 0;
		}
		last=a;
	}
	int now=1;
	for(int i=1;i<=n;i++){
		if(ans[i])
		printf("%d ",ans[i]);
		else{
			while(num[now])now++;
			printf("%d ",now++);
		}
	}
}
//Axyz=xy+yz+zx
// Y k  
// S k+y|k+y+a
//P k+p/k+p+b
// S k+p+s+0~2=k+y+0~1
// 3*k+y+p+a+b=12+j