#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1005],b[1005],used[1005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		int p=lower_bound(b+1,b+n+1,a[i])-b;
		while(used[p])p++;
		a[i]=p,used[p]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j])cnt++;
		}
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++){
		vector<int> vec;
		for(int j=i+1;j<=n;j++)if(a[i]>a[j])vec.push_back(j);
		sort(vec.begin(),vec.end(),[](int x,int y){return b[x]>b[y];});
		for(int j:vec)cout<<i<<' '<<j<<'\n',swap(b[i],b[j]);
	}
	for(int i=1;i<=n;i++)cerr<<b[i]<<' ';
}