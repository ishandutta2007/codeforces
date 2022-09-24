#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int n,a[200005];
ll s=0;
bool isok(int x){
	bool ok=0;
	for(int j=0;j<=60;j++){
		ll t=s>>j,tt=(s+(1ll<<j)-1)>>j;
		if(t<=x&&x<=tt)ok=1;
	}
	return ok;
}
void Solve(){
	scanf("%d",&n),s=0;
	multiset<ll> s1,s2;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
		s1.insert(a[i]);
	}
	s2.insert(s);
	while(s1.size()&&s2.size()){
		ll mx1=*--s1.end(),mx2=*--s2.end();
		if(mx1>mx2)return puts("No"),void();
		if(mx1==mx2){
			s1.erase(s1.find(mx1));
			s2.erase(s2.find(mx2));
			continue;
		}
		s2.erase(s2.find(mx2));
		s2.insert(mx2/2);
		s2.insert((mx2+1)/2);
	}
	puts("Yes");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}