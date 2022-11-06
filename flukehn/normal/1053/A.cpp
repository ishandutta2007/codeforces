#include<bits/stdc++.h>
using namespace std;
typedef long long L;
int n,m,k;
L gcd(L a,L b){while(b)a%=b,swap(a,b);return a;}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n>>m>>k;
	L a=gcd(n,k),N=n/a;
	k/=a;
	L b=gcd(m,k),M=m/b,x,y;
	k/=b;
	if(k>2)return puts("NO"),0;
	puts("YES");
	k=k==1?2:1;
	if(k*N<=n)x=k*N,y=M;
	else x=N,y=k*M;
	printf("0 0\n0 %lld\n%lld 0\n",y,x);
}