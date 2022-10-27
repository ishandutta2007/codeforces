#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	int a[7];
	int k;
	cin>>k;
	int sum=0;
	for(int i=0;i<7;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int ans=1e9;
	for(int i=0;i<7;i++){
		int r=k;
		int l=(r-sum)/sum;
		r-=(l*sum);
		int days=7*l;
		int j=i;
		while(1){
			j%=7;
			if(r==0){
				break;
			}
			days++;
			r-=a[j];
			j++;
		}
		ans=min(ans,days);
	}
	cout<<ans<<endl;
	

}

}