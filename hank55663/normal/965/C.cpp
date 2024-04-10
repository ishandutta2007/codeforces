#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
int main(){
	LL n,k,m,d;
	scanf("%lld %lld %lld %lld",&n,&k,&m,&d);
	//n/x*k<=d
	LL ans=0;
	for(int i = 1;i<=d;i++){
		if(k*(i-1)+1>n)
		break;
		LL x=min(m,n/(k*(i-1)+1)+100);
		for(LL j = x;j>0&&j>=x-200;j--){
			LL round = n/j/k;
			LL ex = n-j*round*k;
			if(ex>=j)round++;
		//	printf("%lld %lld %lld\n",ex,round,j);
			if(round>d)continue;
			ans = max(j*round,ans);
		}
	}
	printf("%lld\n",ans);
}