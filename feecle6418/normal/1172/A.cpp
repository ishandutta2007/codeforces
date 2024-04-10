#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[200005],b[200005];
bool Check(int mid){
	if(mid>0){
		int sa[200005]={0};
		deque<int> qb;
		for(int i=1;i<=n;i++)if(a[i])sa[a[i]]=1;
		for(int i=1;i<=n;i++)qb.push_back(b[i]);
		for(int i=1;i<mid;i++){
			qb.push_back(0);
			int x=qb.front();
			qb.pop_front();
			if(x)sa[x]=1;
		}
		for(int i=1;i<=n;i++){
			if(!sa[i])return 0;
			qb.push_back(i);
			sa[i]=0;
			int x=qb.front();
			qb.pop_front();
			if(x)sa[x]=1;
		}
		return 1;
	}
	int len=1-mid;
	for(int i=n-len+1;i<=n;i++){
		if(b[i]!=i-(n-len))return 0;
	}
	set<int> sa;
	deque<int> qb;
	for(int i=1;i<=n;i++)if(a[i])sa.insert(a[i]);
	for(int i=1;i<=n;i++)qb.push_back(b[i]);
	for(int i=len+1;i<=n;i++){
		if(!sa.count(i))return 0;
		qb.push_back(i);
		sa.erase(i);
		int x=qb.front();
		qb.pop_front();
		if(x)sa.insert(x);
	}
	return 1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int ans=n+2;
	if(b[n]){
		bool fl=1;
		for(int i=n;i>=n-b[n]+1;i--){
			if(b[i]!=i-(n-b[n]))fl=0;
		}
		if(fl){
			if(Check(1-b[n]))return cout<<n-b[n]<<'\n',0;
		}
	}
	int l=1,r=n+1;
	while(l<=r){
		int mid=(l+r)/2;
		if(Check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans+n-1;
}