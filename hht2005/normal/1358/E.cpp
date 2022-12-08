#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int a[maxn],v[maxn];
multiset<int>s;
signed main() {
	int n,x,t=0;
	long long sum=0;
	scanf("%lld",&n);//sdghfjf
	for(int i=1;i<=n/2+n%2;i++) {//esg
		scanf("%lld",a+i);
		sum+=a[i];
	}
	scanf("%lld",&x);
	for(int i=n/2+n%2;i<=n;i++,t++,sum-=a[t])s.insert(v[t+1]=sum+t*x);
	int f=0;
	for(int i=1;i<=n/2+1;i++,f+=x) {
		if(*s.begin()+f>0)return printf("%lld\n",n/2+n%2+i-1),0;
		s.erase(s.find(v[t--]));
	}
	puts("-1");
	return 0;
}