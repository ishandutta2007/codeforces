#include<bits/stdc++.h>
using namespace std;
int n,a[100005],f[605][605];
int main(){
	cin>>n;
	for(int i=0;i<=500;i++)f[i][0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)continue;
		for(int k=0;k<512;k++){
			if(!f[a[i]-1][k])continue;
			if(f[a[i]][k^a[i]])continue;
			f[a[i]][k^a[i]]=1;
			for(int l=a[i]+1;l<=500;l++)f[l][k^a[i]]=1;
		}
	}
	vector<int> ans;
	for(int i=0;i<512;i++)if(f[500][i])ans.push_back(i);
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';
}