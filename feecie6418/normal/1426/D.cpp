#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005],ans=0;
ll s[200005];
map<ll,int> mp;
int main(){
	cin>>n;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		if(!mp.count(s[i])){
			mp[s[i]]=1;
			continue;
		}
		ans++,mp.clear(),mp[s[i]]=mp[s[i-1]]=1;
	}
	cout<<ans;
}