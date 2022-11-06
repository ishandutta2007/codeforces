#include<bits/stdc++.h>
using namespace std;
long long ask(int l,int r){
	if(l>=r)return 0;
	cout<<"? "<<l<<" "<<r<<endl;
	long long ret;
	cin>>ret;
	return ret;
}
void print(int i,int j,int k){
	cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
}
int calc(long long n){
	// (m-1)*m/2 = n
	int p=sqrt(2*n)+1;
	while(1ll*p*(p-1)/2>n)--p;
	return 1ll*p*(p-1)/2==n?p:-1;
}
void work(){
	int n;
	cin>>n;
	long long tot=ask(1,n);
	int l=1,r=n-2;
	while(l<r){
		int m=(l+r+1)>>1;
		long long ret=ask(m,n);
		if(ret==tot)l=m;
		else r=m-1;
	}
	long long cnt=ask(l+1,n);
	int p=tot-cnt+1;
	int q=calc(tot-1ll*p*(p-1)/2);
	print(l,l+p,l+p+q-1);
}
int main(){
#ifdef flukehn
	//freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)work();
}