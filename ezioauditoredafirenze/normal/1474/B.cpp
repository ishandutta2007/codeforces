#include<bits/stdc++.h>
using namespace std;
long long d[30007]={0};
vector<long long> p;
void solve(){
	long long d;
	cin>>d;
	long long a=*lower_bound(p.begin(),p.end(),d+1);
	long long b=*lower_bound(p.begin(),p.end(),d+a);
	cout<<1LL*a*b<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	long long i,j;
	for(i=2;i<30007;i++){
		if(!d[i]){ 
			p.emplace_back(i);
		}
		else{
			continue;
		}
		for(j=i+i;j<30007;j+=i){
			d[j]=1;
		}
	}
	long long t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}