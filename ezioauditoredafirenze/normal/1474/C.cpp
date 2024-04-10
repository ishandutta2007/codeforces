#include<bits/stdc++.h>
using namespace std;
struct item{
	long long a,b;
};
void solve(){
	long long n,i,j=-1,k,mxm=-1;
	cin>>n;
	n*=2;
	long long a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		if(mxm<a[i]){
			mxm=a[i];
			j=i;
		}
	}
	for(i=0;i<n;i++){
		if(j==i){
			continue;
		}
		vector<item> bucket;
		multiset<long long> ms;
		for(k=0;k<n;k++){
			ms.insert(a[k]);
		}
		long long x=mxm+a[i],f=1;
		while(ms.empty()==false){
			long long mx=*ms.rbegin();
			ms.erase(ms.find(mx));
			if(ms.find(x-mx)==ms.end()){
				f=0;
				break;
			}
			ms.erase(ms.find(x-mx));
			item it;
			it.a=mx,it.b=x-mx;
			bucket.emplace_back(it);
			swap(x,mx);
		}
		if(f){
			cout<<"YES"<<endl;
			cout<<mxm+a[i]<<endl;
			for(item it:bucket)
				cout<<it.a<<' '<<it.b<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}