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
using namespace std;
typedef long long LL;
using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	int a[N];
	pii b[N];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int j=0;j<n;j++){
		scanf("%d",&b[j].x);
		b[j].y=j;
	}
	sort(a,a+n);
	sort(b,b+n);
	int ans[N];
	reverse(b,b+n);
	for(int i=0;i<n;i++){
		ans[b[i].y]=a[i];
	}
	for(int i=0;i<n;i++)
	printf("%d ",ans[i]);
	return 0;
}
/*
1 2 2 3 3
7 5 4 3 3
*/