#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll>v;
vector<ll>a,b,c;
ll aa,ab,ac;
vector<ll>ans;
ll sum=0;
void check(vector<ll>&d,ll ad){
	sort(d.begin(),d.end());
	for(int i=1; i<d.size() ;i++){
		if(d[i]-d[i-1]!=d[1]-d[0]) return;
	}
	ans.push_back(ad);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n==1){
		cout << "-1\n";
		return 0;
	}
	for(int i=1; i<=n ;i++){
		int x;cin >> x;v.push_back(x);
		sum+=x;
	}
	sort(v.begin(),v.end());
	a=v;b=v;c=v;
	ll s=v.front();
	ll t=v.back();
	sum=1LL*(s+t)*(n+1)/2-sum;
	aa=sum;
	a.push_back(sum);
	int ab=s+(t-s)/(n-1)*n;
	b.push_back(ab);
	ac=t-(t-s)/(n-1)*n;
	c.push_back(ac);
	check(a,aa);
	check(b,ab);
	check(c,ac);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout << ans.size() << '\n';
	for(auto cur:ans) cout << cur << ' ';
}