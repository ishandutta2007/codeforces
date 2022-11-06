#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll n,a[1000010],ansn;
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n/2;i++) ansn=ansn+(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	cout<<ansn<<endl;
	return 0;
}