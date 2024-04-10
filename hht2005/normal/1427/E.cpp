#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll A[maxn],B[maxn],C[maxn];
int m;
char op[maxn];
ll Xor(ll a,ll b) {
	A[++m]=a,B[m]=b,C[m]=a^b;
	op[m]='^';
	return a^b;
}
ll Add(ll a,ll b) {
	A[++m]=a,B[m]=b,C[m]=a+b;
	op[m]='+';
	return a+b;
}
void calc(ll x) {
	if(x==1)return;
	ll y=x,t=x;
	while(t!=(t&-t))t-=t&-t;
	while((y&-y)!=t)y=Add(y,y);
	ll z=Xor(x,y),p=Add(y,z),q=Xor(x,p),h=Xor(q,Add(y,y));
	for(;h<=y;h=Add(h,h))
		if((h^y)<y)y=Xor(h,y);
	calc(Xor(x,y));
}
int main() {
	int n;
	scanf("%d",&n);
	calc(n);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%lld %c %lld\n",A[i],op[i],B[i]);
	return 0;
}