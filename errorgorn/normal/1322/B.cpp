#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>

int n;
vector<int> v;

int prec[30];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	for (int x=0;x<30;x++) prec[x]=(1<<(x+1))-1;
	
	cin>>n;
	
	int t;
	for (int x=0;x<n;x++){
		cin>>t;
		v.push_back(t);
	}
	
	int res=0;
	for (int b=24;~b;b--){
		int nums=0;
		for (int x=0;x<n;x++) v[x]&=prec[b];
		sort(v.begin(),v.end());
		
		for (int x=0;x<n;x++){
			nums+=lower_bound(v.begin(),v.end(),2*(1<<b)-v[x])-lower_bound(v.begin(),v.end(),1*(1<<b)-v[x]);
			nums+=lower_bound(v.begin(),v.end(),4*(1<<b)-v[x])-lower_bound(v.begin(),v.end(),3*(1<<b)-v[x]);
		}
		
		for (int x=0;x<n;x++){
			int temp=v[x]*2;
			if ((1*(1<<b)<=temp && temp<2*(1<<b))||(3*(1<<b)<=temp && temp<4*(1<<b))) nums--;
		}
		
		//cout<<b<<" "<<nums<<endl;
		
		if ((nums>>1)&1) res+=(1<<b);
	}
	
	cout<<res;
}