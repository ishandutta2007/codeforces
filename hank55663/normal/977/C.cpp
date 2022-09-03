#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long double,null_type,less<long double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ld long double
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[500005];
	a[n+1]=0;
	a[0]=1;
	for(int i =1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n+1);

	if(a[k]==a[k+1])
		printf("-1\n");
	else
		printf("%d\n",a[k]);
}