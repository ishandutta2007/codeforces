#include<iostream>
using namespace std;
typedef long long ll;
ll n,k,a,b;
ll gcd(ll x,ll y){
	if(y==0) return  x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> a >> b;
	ll z=0,z2=n*k+1;
	for(int i=0; i<=n ;i++){
		ll u=i*k-a-b,cx=a,cy=i*k-b;
		if(cx<cy && z<gcd(u,n*k)){
			z=gcd(u,n*k);
		}
		if(cx<cy && z2>gcd(u,n*k)){
			z2=gcd(u,n*k);
		}
		u=i*k-a+b,cx=a,cy=i*k+b;
		if(cx<cy && z<gcd(u,n*k)){
			z=gcd(u,n*k);
		}
		if(cx<cy && z2>gcd(u,n*k)){
			z2=gcd(u,n*k);
		}
		u=i*k+a-b,cx=k-a,cy=i*k-b+k;
		if(cx<cy && z<gcd(u,n*k)){
			z=gcd(u,n*k);
		}
		if(cx<cy && z2>gcd(u,n*k)){
			z2=gcd(u,n*k);
		}
		u=i*k+a+b,cx=k-a,cy=i*k+b+k;
		if(cx<cy && z<gcd(u,n*k)){
			z=gcd(u,n*k);
		}
		if(cx<cy && z2>gcd(u,n*k)){
			z2=gcd(u,n*k);
		}
	}
	cout << n*k/z << ' ' << n*k/z2 << endl;
}