#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int dif[100001];
int a[100001];
int fl[100001],fr[100001];
vector<int>v;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		int l,r;
		cin >> l >> r;
		dif[l-1]++;
		dif[r]--;
	}
	for(int i=1; i<=m ;i++){
		a[i]=a[i-1]+dif[i-1];
		if(v.empty() || a[i]>=v.back()){
			fl[i]=v.size();
			v.push_back(a[i]);
		}
		else{
			fl[i]=lower_bound(v.begin(),v.end(),a[i]+1)-v.begin();
			*lower_bound(v.begin(),v.end(),a[i]+1)=a[i];
		}
	}
	v.clear();
	int ans=0;
	for(int i=m; i>=1 ;i--){
		if(v.empty() || a[i]>=v.back()){
			fr[i]=v.size();
			v.push_back(a[i]);
		}
		else{
			fr[i]=lower_bound(v.begin(),v.end(),a[i]+1)-v.begin();
			*lower_bound(v.begin(),v.end(),a[i]+1)=a[i];
		}
		ans=max(ans,fl[i]+fr[i]+1);
	}
	cout << ans << endl;
}