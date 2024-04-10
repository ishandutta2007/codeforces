#include<bits/stdc++.h>
using namespace std;
const int MAXNUM=500010;
int n,size[MAXNUM];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>size[i];
	if(n==1){
		cout<<size[1]<<endl;
		return 0;
	} 
	sort(size+1,size+1+n);
	long long ans=size[n]-size[1];
	for(int i=2;i<n;i++) if(size[i]<0) ans-=size[i];else ans+=size[i];
	cout<<ans<<endl; 
	return 0;
}