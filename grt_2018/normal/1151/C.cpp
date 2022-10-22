#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
#define ST first
#define ND second

const int mod = 1000*1000*1000+7;
LL l,r;
LL ans_l,ans_r;

int main() {
	scanf("%lld%lld",&l,&r);
	l-=2;
	LL odd=1,even=0;
	LL s=1;
	int t=0;
	while(2*s<=l) {
		l-=2*s;
		s*=2;
		if(t%2==0) {
			even=(even+(s)%mod)%mod;
		}
		else {
			odd=(odd+(s)%mod)%mod;
		}
		t++;
	}
	if(t%2==0) {
		even=(even+((l))%mod)%mod;
	} else {
		odd=(odd+((l))%mod)%mod;
	}
	ans_l = ((((even+1))%mod)*(even))%mod;
	ans_l+= ((((odd))%mod)*((odd)))%mod;
	if(l==-1) ans_l=0;
	odd=1,even=0;
	s=1;
	t=0; r--;
	while(2*s<=r) {
		r-=2*s;
		s*=2;
		if(t%2==0) {
			even=(even+(s)%mod)%mod;
		}
		else {
			odd=(odd+(s)%mod)%mod;
		}
		t++;
	}
	if(t%2==0) {
		even=(even+((r))%mod)%mod;
	} else {
		odd=(odd+((r))%mod)%mod;
	}
	ans_r = (((even+1)%mod)*(even))%mod;
	ans_r+= ((((odd))%mod)*((odd)))%mod;
	ans_r%=mod;
	ans_l%=mod;
	LL res = ans_r - ans_l;
	res = (res+mod)%mod;
	printf("%lld",res);
}