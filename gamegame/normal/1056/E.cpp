#include<iostream>
using namespace std;
typedef long long ll;
const ll b1=137,b2=97;
const ll m1=1e9+7,m2=998244353;
ll pw1[1000001],pw2[1000001];
ll pr1[1000001],pr2[1000001];
string s,t;
int n,m;
int cnt0,cnt1;
int len0,len1;
int ans=0;
pair<ll,ll> getv(int l,int r){
	ll v1=pr1[r]-pr1[l]*pw1[r-l];
	ll v2=pr2[r]-pr2[l]*pw2[r-l];
	v1%=m1;v2%=m2;
	if(v1<0) v1+=m1;
	if(v2<0) v2+=m2;
	return make_pair(v1,v2);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> s >> t;
	n=s.size();
	m=t.size();
	t='?'+t;
	for(int i=0; i<n ;i++){
		if(s[i]=='0') cnt0++;
		else cnt1++;
	}
	pw1[0]=pw2[0]=1;
	for(int i=1; i<=m ;i++){
		pw1[i]=pw1[i-1]*b1%m1;
		pw2[i]=pw2[i-1]*b2%m2;
		pr1[i]=(pr1[i-1]*b1+(t[i]-'a'))%m1;
		pr2[i]=(pr2[i-1]*b2+(t[i]-'a'))%m2;
	}
	for(int i=1; i<=m/n ;i++){
		len0=i;
		len1=(m-len0*cnt0)/cnt1;
		if(len0*cnt0+len1*cnt1!=m) continue;
		if(len0>len1) continue;
		int ptr=0;
		pair<ll,ll> v0,v1;
		bool f0=false,f1=false;
		bool ok=true;
		for(int j=0; j<n ;j++){
			if(s[j]=='0'){
				pair<ll,ll> cur=getv(ptr,ptr+len0);
				ptr+=len0;
				if(!f0) f0=true,v0=cur;
				else if(cur!=v0){
					ok=false;
					break;
				}
			}
			else{
				pair<ll,ll> cur=getv(ptr,ptr+len1);
				ptr+=len1;
				if(!f1) f1=true,v1=cur;
				else if(cur!=v1){
					ok=false;
					break;
				}
			}
		}
		if(len0==len1 && v0==v1) ok=false;
		ans+=ok;
	}
	for(int i=1; i<=m/n ;i++){
		len1=i;
		len0=(m-len1*cnt1)/cnt0;
		if(len0*cnt0+len1*cnt1!=m) continue;
		if(len0<=len1) continue;
		int ptr=0;
		pair<ll,ll> v0,v1;
		bool f0=false,f1=false;
		bool ok=true;
		for(int j=0; j<n ;j++){
			if(s[j]=='0'){
				pair<ll,ll> cur=getv(ptr,ptr+len0);
				ptr+=len0;
				if(!f0) f0=true,v0=cur;
				else if(cur!=v0){
					ok=false;
					break;
				}
			}
			else{
				pair<ll,ll> cur=getv(ptr,ptr+len1);
				ptr+=len1;
				if(!f1) f1=true,v1=cur;
				else if(cur!=v1){
					ok=false;
					break;
				}
			}
		}
		if(len0==len1 && v0==v1) ok=false;
		ans+=ok;
	}
	cout << ans << endl;
}