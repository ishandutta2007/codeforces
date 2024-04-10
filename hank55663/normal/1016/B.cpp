#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	char c[10005];
	scanf("%s",c);
	char b[10005];
	scanf("%s",b);
	int ok[100005];
	for(int i=0;i<n;i++){
		ok[i+1]=1;
		for(int j=0;j<m;j++){
			if(c[i+j]!=b[j])
				ok[i+1]=0;
		}
	}
	for(int i=1;i<=n;i++){
		ok[i]+=ok[i-1];
	}
	//printf("%d\n",ok[5]);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(r-l+1>=m)
		printf("%d\n",ok[r+1-m]-ok[l-1]);
		else
		printf("0\n");
	}
}