#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double> 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	LL x[300005];
	for(int i = 0;i<n;i++)
		scanf("%lld",&x[i]);
	LL gcd=x[1]-x[0];
	for(int i =1;i<n-1;i++){
		gcd=__gcd(gcd,x[i+1]-x[i]);
	}
	for(int i = 0;i<m;i++){
		LL p;
		scanf("%lld",&p);
		if(gcd%p==0){
			printf("YES\n%lld %d\n",x[0],i+1);
			return 0;
		}
	}
	printf("NO\n");
}