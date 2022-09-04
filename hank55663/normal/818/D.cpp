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
	int c[100005];
	int color[1000005];
int main(){
	int n,a;
	scanf("%d %d",&n,&a);
	MEM(color);
	int last=0;
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		if(color[c[i]]>=last)
		color[c[i]]++;
		if(c[i]==a){
			last++;
		}
	}
	for(int i=1;i<=1e6;i++){
		if(color[i]>=last&&i!=a){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1\n");
}
//Axyz=xy+yz+zx
// Y k  
// S k+y|k+y+a
//P k+p/k+p+b
// S k+p+s+0~2=k+y+0~1
// 3*k+y+p+a+b=12+j