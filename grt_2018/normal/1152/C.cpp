#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int a,b,k;
LL ans=(LL)1000*1000*1000*1000*1000*1000;

void go_through_divisors(int x) {
	for(int i=1; i*i<=x;i++) {
		if(x%i==0) {
			for(int j=0; j<2;j++) {
				int new_b = (((b-1)/i)+1)*i;
				int tmp = new_b-b;
				LL lcm = (LL)(a+tmp)*(b+tmp)/__gcd(a+tmp,b+tmp);
				if(lcm<ans||(lcm==ans&&tmp<k)) {
					ans=lcm;
					k=tmp;
				}
				i = x/i;
			}
		}
	}
}

int main() {
	scanf("%d%d",&a,&b);
	if(a<b) swap(a,b);
	go_through_divisors(a-b);
	printf("%d",k);
}