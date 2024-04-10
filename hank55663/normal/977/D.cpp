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
	int n;
	scanf("%d",&n);
	pll p[105];
	for(int i = 0;i<n;i++){
		LL x;
		scanf("%lld",&x);
		LL temp=x;
		int cnt=0;
		while(temp%3==0){
			temp/=3;
			cnt++;
		}
		p[i]=mp(-cnt,x);
	}
	sort(p,p+n);
	for(int i = 0;i<n;i++)
	printf("%lld ",p[i].y);
}