	#include<bits/stdc++.h>
	using namespace std;
	#define pn cout<<"NO\n";
	#define py cout<<"YES\n";
	int T,n,i,j,fl,ans,a[500005];
	long long sum;
	priority_queue<int>p;
	int main(){
		ios::sync_with_stdio(false);
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i){
			if(a[i]>=0){
				sum+=a[i];++ans;
			}
			else {
				if(sum+a[i]>=0)sum+=a[i],++ans,p.push(-a[i]);
				else if(p.size()&&p.top()>=-a[i]){
					sum+=p.top();sum+=a[i];
					p.pop();p.push(-a[i]);
				}
			}
		}
		cout<<ans;
	}