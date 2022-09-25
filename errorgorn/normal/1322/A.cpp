#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>

int n;
string s;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>n;
	cin>>s;
	
	int ans=0;
	int curr=0;
	bool bad=false;
	for (int x=0;x<n;x++){
		if (s[x]==')') curr--;
		else curr++;
		
		if (curr<0) bad=true;
		if (bad) ans++;
		if (curr==0) bad=false;
	}
	
	if (curr!=0){
		cout<<"-1";
		return 0;
	}
	cout<<ans;
}