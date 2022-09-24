#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,inf=1e9;
int a[105][105],n;
vector<vector<int>> ans;
bool Judge(){
	for(int i=1;i<=n;i++)sort(a[i]+1,a[i]+n+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[i][j]!=j)return 0;
	return 1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	while(!Judge()){
		vector<int> p(n);
		for(int i=1;i<=n;i++){
			bool ok=0;
			for(int j=2;j<=n&&!ok;j++)if(a[i][j]==a[i][j-1])p[i-1]=a[i][j],ok=1;
			if(ok){
				int lst=p[i-1];
				for(int j=i%n+1;j!=i;j=j%n+1){
					bool t=0;
					for(int k=2;k<=n&&!t;k++)
						if(a[j][k]==a[j][k-1])p[j-1]=a[j][k],t=1;
					if(!t)p[j-1]=lst;
					else lst=p[j-1];
				}
				break;
			}
		}
		ans.push_back(p);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==p[i-1]){
					a[i][j]=p[(i-2+n)%n];
					break;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
//			puts("");
//		}
//		puts("");
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j>=2;j--){
			vector<int> p(n);
			for(int k=0,t=j;k<n;k++)p[k]=t,t=t%n+1;
			ans.push_back(p);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		for(auto j:i)cout<<j<<' ';
		puts("");
	}
}