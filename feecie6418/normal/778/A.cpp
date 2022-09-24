#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,inf=2e9;
string s,t;
int p[200005],q[200005];
bool Check(int mid){
	for(int i=0,j=0;i<t.size();i++){
		while(j<s.size()&&(s[j]!=t[i]||q[j]<mid))j++;
		if(j==s.size())return 0;
		j++;
	}
	return 1;
}
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++)cin>>p[i],p[i]--,q[p[i]]=i;
	int l=0,r=s.size()-1,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(Check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}