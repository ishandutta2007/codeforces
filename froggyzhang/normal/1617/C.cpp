#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n;
void Solve(){
	vector<int> A,B;
	static bool vis[N];	
	cin>>n;
	for(int i=1;i<=n;++i){
		vis[i]=0;
	}
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		if(x>n||vis[x])A.push_back(x);
		if(x<=n)vis[x]=1;	
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])B.push_back(i);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(int i=0;i<(int)A.size();++i){
		if((A[i]-1)/2<B[i]){
			cout<<-1<<'\n';
			return;
		}
	}
	cout<<A.size()<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}