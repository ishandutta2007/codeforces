#include<bits/stdc++.h>
using namespace std;
int n,is[2005],sec;
void Solve(){
	cin>>n,memset(is,0,sizeof(is));
	for(int i=2;i<=n;i++){
		cout<<"? 1 "<<i-1<<endl<<i<<endl;
		for(int j=1;j<i;j++)cout<<j<<' ';
		cout<<endl;
		int ret;
		cin>>ret;
		if(ret){
			sec=i,is[i]=1;
			break;
		}
	}
	int l=1,r=sec-1,ans=0;
	while(l<=r){
		int mid=(l+r)/2,ret;
		cout<<"? 1 "<<mid<<endl<<sec<<endl;
		for(int j=1;j<=mid;j++)cout<<j<<' ';
		cout<<endl;
		cin>>ret;
		if(ret)r=mid-1,ans=mid;
		else l=mid+1;
	}
	is[ans]=1;
	for(int i=sec+1,ret;i<=n;i++){
		cout<<"? 1 1"<<endl<<sec<<endl<<i<<endl,cin>>ret;
		if(ret)is[i]=1;
	}
	int cnt=0;
	for(int j=1;j<=n;j++)if(!is[j])cnt++;
	cout<<"! "<<cnt<<' ';
	for(int j=1;j<=n;j++)if(!is[j])cout<<j<<' ';
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}