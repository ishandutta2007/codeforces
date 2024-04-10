#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mg=500;
int n;
string s;
//unordered_map<ll,int>mp;
int pf[200001];
ll dp[200001];
vector<int>v;
ll ans=0;
ll f(ll x,ll y,ll z){
	//cout << "f: " << x << ' ' << y << ' ' << z << endl;
	ll duh=x*y-(x%z)*(y%z);
	x%=z;
	y%=z;
	//cout << duh/z+min(x,y) << endl;
	return duh/z+min(x,y);
}
int mp[84400001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> s;n=s.size();s='?'+s;
	//n=200000;
	//for(int i=1; i<=n ;i++) s+='1';
	//s='?'+s;
	for(int i=1; i<=n ;i++) pf[i]=pf[i-1]+(s[i]=='1');
	for(int i=0; i<=(n/mg) ;i++){
		int ptr=-1;
		for(int j=1; j<=n ;j++){
			while(ptr+1<j && pf[j]-pf[ptr+1]>mg) mp[dp[++ptr]+n]++;
			//cout << i << ' ' << j << ' ' << ptr << endl;
			dp[j]=dp[j-1];
			if(s[j]=='1') dp[j]+=i;
			else dp[j]--;
			ans+=mp[dp[j]+n];
			//cout << dp[j] << endl;
		}
		for(int j=0; j<=ptr ;j++) mp[dp[j]+n]=0;
		//cout << ans << endl;
	}
	//cout << ans << endl;
	v.push_back(0);
	for(int i=1; i<=n ;i++) if(s[i]=='1') v.push_back(i);
	v.push_back(n+1);
	//cout << f(1,3,2) << ' ' << f(0,2,2) << ' ' << f(0,3,2) << ' ' << f(1,2,2) << endl;
	for(int i=1; i<v.size()-1 ;i++){
		for(int j=max(1,i-mg+1); j<=i ;j++){
			int cnt=i-j+1;
			int l1=v[j-1],r1=v[j];
			int l2=v[i],r2=v[i+1];
			ll add=f(r1,r2,cnt)-f(l1,r2,cnt)-f(r1,l2,cnt)+f(l1,l2,cnt);
			//cout << "total: "<< add << endl;
			ans+=add;
			//cout << ans << ' ' << add << ' ' << i << ' ' << j << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << cnt << endl;
		}
	}
	cout << ans << '\n';
}