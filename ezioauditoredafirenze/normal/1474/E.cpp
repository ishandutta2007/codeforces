#include<bits/stdc++.h>
using namespace std;
struct item{
	long long a,b;
};
void solve(){
	long long n,i;
	cin>>n;
	long long result=(n-1)*(n-1),c=1,v=n-2,last=n;
	long long p[n+1];
	for(i=0;i<=n;i++){
		p[i]=1;
	}
	vector<item> bucket;
	for(;c+1<n;){
		if(c<n-2){
			result+=2*v*v;
			c=c+2;
			v--;
		}
		else{
			result+=v*v;
			c++;
		}
	}
	cout<<result<<endl;
	result=(n+1)/2;
	for(i=0;i<(n-1)/2;i++){
		p[last]=result;
		item it;
		it.a=result,it.b=n;
		bucket.emplace_back(it);
		last=result;result--;
	}
	last=1;result=(n+1)/2+1;
	for(i=0;i<n/2;i++){
		p[last]=result;
		item it;
		it.a=result;it.b=1;
		bucket.emplace_back(it);
		last=result;result++;
	}
	for(i=1;i<=n;i++){
		cout<<p[i]<<' ';
	}
	cout<<endl<<n-1<<endl;
	for(item it:bucket){
		cout<<it.a<<' '<<it.b<<endl;
	}
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