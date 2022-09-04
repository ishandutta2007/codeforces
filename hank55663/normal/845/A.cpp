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
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[205];
	for(int i=0;i<2*n;i++)
	scanf("%d",&a[i]);
	sort(a,a+2*n);
	printf("%s\n",a[n]==a[n-1]?"NO":"YES");
}
/*
14%20,15#17
20,14-18
1#5,11,4%10,14-18,20,21
11,21,20,14-18,4%10,1#5

*/