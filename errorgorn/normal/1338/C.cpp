#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

ll n;

const int two[]={0,2,3,1};
const int three[]={0,3,1,2};

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		ll base=4;
		
		while (base<=n) base<<=2;
		
		base>>=2;
	
		ll index;
		
		index=n-base;
		
		if (index%3==0){ //you are the first
			cout<<base+index/3<<endl;
		}
		else if (index%3==1){
			index/=3;
		
			ll curr=1;
			ll delta=0;
			 
			while (curr<base){
				delta+=two[index&3]*curr;
				
				curr<<=2;
				index>>=2;
			}
			
			cout<<base*2+delta<<endl;
		}
		else{
			index/=3;
		
			ll curr=1;
			ll delta=0;
			 
			while (curr<base){
				delta+=three[index&3]*curr;
				
				curr<<=2;
				index>>=2;
			}
			
			cout<<base*3+delta<<endl;
		}
	}
	
}