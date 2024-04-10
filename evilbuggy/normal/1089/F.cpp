#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

typedef pair<int, int> pi;

// int lpf[100005];
bool prime[100005];

void precompute(){
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i < 100005; i++){
		if(prime[i]){
			for(int j = 2*i; j < 100005; j += i){
				if(prime[j]){
					prime[j] = false;
				}
			}
		}
	}
}

map<int,int> pf;
int n;

void decompose(){
	int maxi=(1e5)+5 ;
	int left=n ;
	for(int i=2 ; i<maxi ; i++){
		while(left%i==0){
			pf[i]=1 ;
			left/=i ;
		}
	}
	if(left!=1)
		pf[left]=1 ;
}

ll po(int a, int b, int mod)
{
	if(b==0)
		return 1LL ;
	ll x=po(a, b/2, mod) ;
	x=(x*x)%mod ;
	if(b%2==1){
		x=(x*a)%mod ;
	}
	return x ;
}

int main(){
	precompute();
	// int n;
	cin>>n;
	decompose();
	if(pf.size() < 2){
		cout<<"NO"<<endl;
		exit(0);
	}
	cout<<"YES"<<endl;
	cout << 2 << endl ;
	auto iter=pf.begin() ;
	ll p=iter->first ;
	iter++ ;
	ll q=iter->first ;
	// cout << p << q << endl ;
	ll inv=po(p,q-2,q) ;
	
	ll a=((q-1)*inv)%q ;
	ll b=((n-1)-p*a)/q ;
	cout << a << " " << n/p << endl ;
	cout << b << " " << n/q << endl ;
}