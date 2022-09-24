#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100005];
int n;
void Solve(){
	cin>>n>>a+1;
	int mx=-1;
	for(int i='a';i<='z';i++){
		vector<int> pos,pos2,p3;
		pos2.push_back(0);
		for(int j=1;j<=n;j++)if(a[j]!=i)pos.push_back(a[j]),pos2.push_back(j);
		pos2.push_back(n+1);
		bool flag=0;
		for(int j=0;j<pos.size();j++)if(pos[j]!=pos[pos.size()-j-1])flag=1;
		if(flag)continue;
		for(int j=1;j<pos2.size();j++)p3.push_back(pos2[j]-pos2[j-1]-1);
		int ans=pos.size();
		//cout<<ans<<'\n';
		for(int j=0;j<=(p3.size()-1)/2;j++){
			if(j!=p3.size()-1-j)ans+=2*min(p3[j],p3[p3.size()-1-j]);
			else ans+=p3[j];
		}
		mx=max(mx,ans);
		//cout<<(char)i<<' '<<ans<<'\n';
	}
	if(mx!=-1)cout<<n-mx<<'\n';
	else puts("-1");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}