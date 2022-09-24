#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+9;
typedef long long ll;
struct Triple{
	int l1,r1;
	bool operator <(const Triple t) const {
		return (r1-l1)^(t.r1-t.l1)?(r1-l1)<(t.r1-t.l1):l1<t.l1;
	}
};
vector<int> pos[100005];
vector<Triple> t;
int n,a[100005],cnt,b[100005];
ll hsh[100005],bc[100005]={1};
unordered_map<int,int> mp;
ll GetHash(int l,int r){
	return (hsh[r]-hsh[l-1]*bc[r-l+1]%mod+mod)%mod;
}
int main(){
	cin>>n;
	for(int i=1;i<=100000;i++)bc[i]=bc[i-1]*233%mod;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!mp[a[i]])mp[a[i]]=++cnt,b[cnt]=a[i];
		a[i]=mp[a[i]],pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)hsh[i]=(hsh[i-1]*233+a[i])%mod;
	for(int i=1;i<=n;i++){
		if(pos[i].size()<1)continue;
		for(int j:pos[i]){
			for(int k:pos[i]){
				if(j>=k||2*k-j-1>n)continue;
				if(GetHash(j,k-1)==GetHash(k,2*k-j-1))t.push_back({j,k-1});
			}
		}
	}
	sort(t.begin(),t.end());
	int nowr=0;
	for(Triple x:t){
		if(x.l1<=nowr)continue;
		nowr=x.r1;
	}
	cout<<n-nowr<<endl;
	for(int i=nowr+1;i<=n;i++)cout<<b[a[i]]<<' ';
    return 0;
}