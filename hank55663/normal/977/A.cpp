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
	while(k--){
		if(n%10==0)n/=10;
		else n--;
	}
	printf("%d\n",n);
}