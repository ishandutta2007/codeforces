#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005],f[200005],n;
void Solve(){
	map<int,int> mp;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		mp[a[i]]=1;
		f[i]=f[i+1];
		while(mp[f[i]])f[i]++;
	}
	vector<int> ans;
	for(int i=1,j;i<=n;i=j){
		j=i;
		mp.clear();
		ans.push_back(f[i]);
		int t=0;
		while(t!=f[i]){
			mp[a[j]]=1;
			j++;
			while(mp[t])t++;
		}
		if(j==i)j=i+1;
	}
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';
	puts("");
	for(int i=n;i>=1;i--)f[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}