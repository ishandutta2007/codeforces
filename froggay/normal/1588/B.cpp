#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll Ask(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	ll x;
	cin>>x;
	return x;
}
void Solve(){
	cin>>n;
	int l=1,r=n+1,pos=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(Ask(1,mid)){
			pos=r=mid;
		}
		else{
			l=mid+1;
		}	
	}	
	int i=pos-1;
	int j=Ask(i,n)-Ask(i+1,n)+i+1;
	int k=Ask(j,n)-Ask(j+1,n)+j;
	cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}