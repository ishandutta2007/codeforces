#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,N=2e6;
ll n,m,a[100005],t,s;
int main(){
	cin>>n>>m>>s>>t,s--,m--;
	while(t%n){
		if(s<=m)s=(s+t)%n;
		else s=((s-t)%n+n)%n;
		t--;
	}
	if(!t)return cout<<s+1,0;
	while(t){
		if(t%n==0){
			if(!a[s])a[s]=t;
			else {
				t%=a[s]-t;
				break;
			}
		}
		if(s<=m)s=(s+t)%n;
		else s=((s-t)%n+n)%n;
		t--;
	}
	while(t){
		if(s<=m)s=(s+t)%n;
		else s=((s-t)%n+n)%n;
		t--;
	}
	cout<<s+1;
}