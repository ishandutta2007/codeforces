#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll m,n,k,a[100010];
long double ansn;
int main(){
	read(n);read(m);read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	ll su=0;
	for (int i=n;i>=1;i--){
		su+=a[i];
		ll p=k;p-=i-1;
		if (p>=0){
			ansn=max(ansn,1.0l*(su+min(m*(n-i+1),p))/(n-i+1));
		}
	}
	printf("%.10Lf",ansn);
	return 0;
}