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
typedef complex<double> C;
int main()
{
	LL x;
	scanf("%lld",&x);
	LL ans=0;
	LL temp=1;
	while(x!=1){
		ans+=x/2*temp;
		x=x-x/2;
		temp<<=1;
	}
	printf("%lld\n",ans);
}