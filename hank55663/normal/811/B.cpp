#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 300005
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int p[10005];
	for(int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	while(m--){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		if(x<l||x>r)
		printf("Yes\n");
		else{
			int rr=0,ll=0;
			int a=p[x];
			for(int i=l;i<=r;i++){
				if(i!=x){
					if(p[i]>a)
					rr++;
					else
					ll++;
				}
			}
		//	printf("%d %d\n",rr,ll);
			if(ll+l==x){
				printf("Yes\n");
			}
			else
			printf("No\n");
		}
	}
    return 0;
}