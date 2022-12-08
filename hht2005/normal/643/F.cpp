#include<bits/stdc++.h>
using namespace std;
int f[150],p;
unsigned C[200],A=1;
unsigned qpow(unsigned a,int b) {
	unsigned ans=1;
	while(b) {
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
void add(int x,int v) {
	for(int i=2;i<=p;i++) {
		while(x%i==0) {
			f[i]+=v;
			x/=i;
		}
	}
	A*=x;
}
int main() {
	int n,q;
	scanf("%d%d%d",&n,&p,&q);
	p=min(n-1,p);
	C[0]=1;
	for(int i=1;i<=p;i++) {
		add(i,-1);
		add(n-i+1,1);
		C[i]=A;
		for(int j=2;j<=p;j++)
			C[i]*=qpow(j,f[j]);
	}
	unsigned sum=0;
	for(int i=1;i<=q;i++) {
		unsigned ans=0;
		for(int j=0,P=1;j<=p;j++,P*=i) {
			ans+=C[j]*P;
		}
		sum^=ans*i;
	}
	printf("%u\n",sum);
	return 0;
}