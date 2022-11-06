#include<bits/stdc++.h>
#define ll long long
#define mo 998244353
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll ansn,su=1,n;
int main(){
	read(n);
	for (ll i=1;i<=n;i++) su=su*i%mo;
	for (ll i=1;i<n;i++){
		ansn=ansn*(i+1)%mo;
		ansn=(ansn+i*(n-i-1))%mo;
	}
	cout<<(ansn+su)%mo<<endl;
	return 0;
}