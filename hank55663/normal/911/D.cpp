#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[1555];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i])
			cnt++;
		}
	}
	cnt%=2;
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		int k=r-l+1;
		k=k*(k-1)/2;
		if(k&1)		cnt^=1;
		printf("%s\n",cnt?"odd":"even");
	} 
}