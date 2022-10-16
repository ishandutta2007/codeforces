#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
inline int Ask(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int l=1,r=1e9+1,len=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(Ask(mid)==1){
			len=mid,r=mid;
		}
		else{
			l=mid+1;
		}
	}
	int ans=len;
	--len;
	for(int i=2;i<=n;++i){
		if(!(len/i))break;
		int t=Ask(len/i);
		if(!t)break;
		if(t==i)ans=min(ans,(len/i)*t);
	}
	cout<<"! "<<ans<<endl;
	return 0;
}