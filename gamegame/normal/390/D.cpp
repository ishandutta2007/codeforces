#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	bool sw=(n>m);
	if(n>m) swap(n,m);
	vector<int>ans1,ans2;
	for(int i=2; i<=n+1 ;i++){
		for(int j=1; j<=i-1 ;j++){
			ans1.push_back(j);
			ans2.push_back(i-j);
		}
	}
	for(int i=n+2; i<=m ;i++){
		for(int j=1; j<=n ;j++){
			ans1.push_back(j);
			ans2.push_back(i-j);
		}
	}
	for(int i=m+1+(n==m); i<=n+m ;i++){
		for(int j=i-m; j<=n ;j++){
			ans1.push_back(j);
			ans2.push_back(i-j);
		}
	}
	long long cost=0;
	for(int i=0; i<k ;i++){
		cost+=ans1[i]+ans2[i]-1;
	}
	cout << cost << endl;
	for(int i=k-1; i>=0 ;i--){
		int o[2];
		for(int j=1; j<=ans1[i] ;j++){
			o[0]=j;o[1]=1;
			cout << '(' << o[sw] << ',' << o[!sw] << ") ";
		}
		for(int j=2; j<=ans2[i] ; j++){
			o[0]=ans1[i];o[1]=j;
			cout << '(' << o[sw] << ',' << o[!sw] << ") ";
		}
		cout << endl;
	}
}