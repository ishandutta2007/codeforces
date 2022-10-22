#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int N=1e6+5;
//const ll mod=1e9+7;
int n,cur;
string s,ans;
ll v1=1e9+7,h1=998244353,v2=993244853,h2=1e9+7;
ll pw1[N],pw2[N];
ll hv1[N],hv2[N],hv3[N],hv4[N];
ll mypow(ll a,ll b,ll mod)
{
	if(!a) return 1LL;
	ll t=mypow(a,b/2,mod);
	if(b&1) return t*t%mod*a%mod;
	return t*t%mod;
}
void Add(string s)
{
	for(int i=0;i<s.size();i++){
		hv1[cur+1]=(hv1[cur]+(ll)s[i]*pw1[cur]%h1)%h1;
		hv2[cur+1]=(hv2[cur]+(ll)s[i]*pw2[cur]%h2)%h2;
		cur++;
	}
}
string Do(string s)
{
	int val=0;
	for(int i=0;i<s.size();i++){
		hv3[val+1]=(hv3[val]+(ll)s[i]*pw1[val]%h1)%h1;
		hv4[val+1]=(hv4[val]+(ll)s[i]*pw2[val]%h2)%h2;
		val++;
	}
	string res;
	int l=0;
	for(int i=s.size();i>=1;i--){
		if(hv3[i]*pw1[cur-i]%h1==(hv1[cur]-hv1[cur-i]+h1)%h1 &&
		hv4[i]*pw2[cur-i]%h2==(hv2[cur]-hv2[cur-i]+h2)%h2){
			l=i; break;
		}
	}
	for(int i=l;i<s.size();i++) res+=s[i];
	return res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=1e6;i++){
		pw1[i]=pw1[i-1]*v1%h1;
		pw2[i]=pw2[i-1]*v2%h2;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(i==1){
			ans=s;
			Add(s);
		}
		else{
			string res=Do(s);
			ans+=res;
			Add(res);
		}
	}
	cout<<ans;
    return 0;
}