#include <iostream>
#include <cstring>
using namespace std;

long long cal(long long x) {
	if(x==0) return 0;
	long long ret=0;
	int u[99]; memset(u, 0, sizeof(u)); u[1]=1;
	for(int i=1; i<64; ++i) for(int j=i*2; j<64; j+=i) u[j]-=u[i];
	for(int num=2; num<64; ++num)
		for(int len=1; len<64; ++len) {
			long long le=1ll<<(len-1);
			long long c=0; for(int k=1; k<=num; ++k) c=(c<<len)+1;
			long long ri=min((1ll<<len)-1, x/c);
			if(le<=ri) ret+=(ri-le+1)*u[num];
			//if(le<=ri) cout<<"num="<<num<<" len="<<len<<" cur="<<ri-le+1<<endl;
		}
	/*
	u[1]=1;
	for(int i=1; i<64; ++i) {
		//cout<<"u["<<i<<"]="<<u[i]<<endl;
		for(int j=i*2; j<64; j+=i) u[j]-=u[i];
		for(int j=2; j<64; ++j) {
			long long le=1ll<<(i-1);
			long long c=0; for(int k=1; k<=j; ++k) c=(c<<i)+1;
			long long ri=min((1ll<<i)-1, x/c);
			if(le<=ri) ret+=(ri-le+1)*u[i];
			if(le<=ri && (ri-le+1)*u[i]) 
			//if(i<5&&j<5)
			//cout<<"i="<<i<<" j="<<j<<" l="<<le<<" r="<<ri<<" x="<<x<<" c="<<c<<" t="<<(ri-le+1)<<" u="<<u[i]<<endl;
		}
	}
	*/
	return -ret;
}

int main() {
	long long l, r; cin>>l>>r;
	cout<<cal(r)-cal(l-1)<<endl;
	return 0;
}