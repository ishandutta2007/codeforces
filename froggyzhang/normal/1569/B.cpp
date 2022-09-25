#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
char s[N],ans[N][N];
int n;
void Solve(){
	cin>>n>>(s+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ans[i][j]=(i==j?'X':'=');		
		}
	}
	vector<int> a;
	for(int i=1;i<=n;++i){
		if(s[i]=='2'){
			a.push_back(i);
		}	
	}
	if(a.size()==1||a.size()==2){
		cout<<"No\n";
		return;
	}
	for(int i=0;i<(int)a.size();++i){
		ans[a[i]][a[(i+1)%a.size()]]='+';
		ans[a[(i+1)%a.size()]][a[i]]='-';
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}