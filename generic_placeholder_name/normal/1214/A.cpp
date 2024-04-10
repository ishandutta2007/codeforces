#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main(){
	ll n, d, e, cntd, cnte, min=1e9;
	cin>>n>>d>>e; e*=5; cntd=n/d; cnte=0;
	while (cntd>0){
	    if (min>((n-cntd*d)%e)) min=(n-cntd*d)%e;
	    cntd--;
	}
	if (min>((n-cntd*d)%e)) min=(n-cntd*d)%e;
	cout<<min;
	return 0;
}