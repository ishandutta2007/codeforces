#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
inline int gcd(int x,int y) {
	if(!x||!y)return x^y;
	return gcd(y,x%y);
}
int main() {
	int n,X=0,Z=0;
	long long Y=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		X=max(X,a[i]);
	}
	for(int i=1;i<=n;i++)
		Z=gcd(Z,X-a[i]);
	for(int i=1;i<=n;i++)
		Y+=(X-a[i])/Z;
	cout<<Y<<' '<<Z<<endl;
	return 0;
}