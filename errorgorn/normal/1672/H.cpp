#include <bits/stdc++.h>
using namespace std;

int n,q;
string s;
int l[200005];
int r[200005];
int psum[200005];
int balance[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	cin>>s;
	
	s=s[0]+s+s[n-1];
	
	for (int x=1;x<=n;x++){
		if (s[x-1]==s[x]) l[x]=x;
		else l[x]=l[x-1];
	}
	
	for (int x=n;x>=1;x--){
		if (s[x]==s[x+1]){
			r[x]=x;
			psum[x]=1;
			if ((x-l[x])%2==0){
				balance[x]=(s[x]=='1'?1:-1);
			}
		}
		else r[x]=r[x+1];
	}
	
	for (int x=1;x<=n;x++){
		psum[x]+=psum[x-1];
		balance[x]+=balance[x-1];
	}
	
	int a,b;
	while (q--){
		cin>>a>>b;
		a=l[a],b=r[b];
		
		int bl=balance[b]-balance[a-1];
		int sum=psum[b]-psum[a-1];
		
		int ans=(sum+abs(bl))/2;
		
		if ((sum+abs(bl))%2==1) ans++;
		else if (abs(bl)==0) ans++;
		else if (bl>0 ^ s[a]=='1') ans++;
		
		cout<<ans<<"\n";
	}
}