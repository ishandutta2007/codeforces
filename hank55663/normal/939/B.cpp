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
	LL n,k;
	scanf("%lld %lld",&n,&k);
	LL ans=-1,ansi,ansnum;
	for(int i = 1;i<=k;i++){
		LL x;
		scanf("%lld",&x);
		LL tot= n/x*x;
		if(tot>ans){
			ans=tot;
			ansi=i;
			ansnum=n/x;
		}
	}
	printf("%lld %lld\n",ansi,ansnum);
}