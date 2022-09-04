#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
int main(){
	int t[1005];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	int d;
	d=t[1]-t[0];
	for(int i=1;i<n;i++){
		if(d!=t[i]-t[i-1])
		d=1e9;
	}
	if(d==1e9){
		printf("%d\n",t[n-1]);
	}
	else{
		printf("%d\n",t[n-1]+d);
	}
}