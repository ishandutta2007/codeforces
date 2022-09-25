
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'


int n;


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		if (n==1){
			cout<<-1;
		}
		else{
			if ((2*n+1)%3==0) cout<<4;
			else cout<<2;
			for (int x=2;x<n;x++) cout<<2;
			cout<<3;
		}
		
		cout<<endl;
	}	
}