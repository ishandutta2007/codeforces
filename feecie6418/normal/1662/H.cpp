#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>n>>m;
		vector<int> ans;
		for(int i=1;i*i<=n+m-2;i++){
			if((n+m-2)%i)continue;
			if((n%i==0&&(m-2)%i==0)||(m%i==0&&(n-2)%i==0)||((n-1)%i==0&&(m-1)%i==0)){
				ans.push_back(i);
			}
			int j=(n+m-2)/i;
			if(i==j)continue;
			if((n%j==0&&(m-2)%j==0)||(m%j==0&&(n-2)%j==0)||((n-1)%j==0&&(m-1)%j==0)){
				ans.push_back(j);
			}
		}
		ans.push_back(2);
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end())-ans.begin());
		cout<<ans.size()<<' ';
		for(int i:ans)cout<<i<<' ';
		puts("");
	}
}