#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
int main(){
	int q; cin>>q; for(int l=1; l<=q; l++) {
		ll n, x; cin>>n>>x; ll d[n], h[n], dmg[n];
		for(ll i=0; i<n; i++) {
			cin>>d[i]>>h[i]; dmg[i]=d[i]-h[i];
		}
		ll maxd=d[0]; for(ll i=1; i<n; i++) {
			if (d[i]>maxd) maxd=d[i];
		}
		ll maxdmg=dmg[0]; for(ll i=1; i<n; i++) {
			if (dmg[i]>maxdmg) maxdmg=dmg[i];
		}
		if(maxdmg<=0) {
			if (x<=maxd) cout<<1<<endl;
			else cout<<-1<<endl;
		}
		else cout<<(ll)ceil((double)max(x-maxd, 0LL)/(double)maxdmg)+1<<endl;
	}
}