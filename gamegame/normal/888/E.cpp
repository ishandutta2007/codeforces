#include<iostream>
#include<cmath>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,k;
ll m;
ll a[35],b[262144],e[262144];
ll c[262144],d[262144];
vector<ll>s,t;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	k=n/2;
	for(int i=0; i<n ;i++){
		cin >> a[i];
		if(i<k) b[(1<<i)]=a[i];
		else e[1<<(i-k)]=a[i];
	}
	for(int i=0; i<(1<<k) ;i++){
		ll j=(i&-i);
		c[i]=(c[i-j]+b[j])%m;
		s.push_back(c[i]);
	}
	for(int i=0; i<(1<<(n-k)) ;i++){
		ll j=(i&-i);
		d[i]=(d[i-j]+e[j])%m;
		t.push_back(d[i]);
	}
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	int ptr=t.size()-1;
	ll ans=0;
	for(int i=0; i<s.size() ;i++){
		while(ptr>=0 && s[i]+t[ptr]>=m) ptr--;
		if(ptr<0) break;
		ans=max(ans,s[i]+t[ptr]);
	}
	if(!t.empty() && !s.empty()) ans=max(ans,(s.back()+t.back())%m);
	if(!t.empty()) ans=max(ans,t.back());
	if(!s.empty()) ans=max(ans,s.back());
	cout << ans << endl;
}