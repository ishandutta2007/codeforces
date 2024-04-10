#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int Ask(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl;
	char opt;
	cin>>opt;
	return opt=='x';	
}
void Solve(){
	int p=1;
	while(!Ask(p,p<<1))p<<=1;
	if(p==1){
		if(Ask(2,3))cout<<"! "<<1<<endl;
		else cout<<"! "<<2<<endl;
		return;
	}
	int ans=p,l=p+1,r=p<<1|1;
	while(l<r){
		int mid=(l+r)>>1;
		if(Ask(l-1,mid))ans=r=mid;
		else l=mid+1;
	}
	cout<<"! "<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string T;
	while(cin>>T){
		if(T!="start")break;
		Solve();
	}
	return 0;
}