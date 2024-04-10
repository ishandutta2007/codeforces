#include<bits/stdc++.h>
using namespace std;
int n,pl[100005],prod[100005];
int Power(int x,int y,int mod){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	cin>>n;
	if(n==4)return puts("YES\n1 3 2 4"),0;
	for(int i=2;i*i<=n;i++)if(n%i==0)return puts("NO"),0;
	pl[1]=prod[1]=1;
	for(int i=2;i<=n;i++){
		pl[i]=1ll*Power(prod[i-1],n-2,n)*i%n;
		prod[i]=1ll*prod[i-1]*pl[i]%n;
	}
	puts("YES");
	for(int i=1;i<=n;i++)cout<<(pl[i]==0?n:pl[i])<<' ';
	cout<<endl;
    return 0;
}