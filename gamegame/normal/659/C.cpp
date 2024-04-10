#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>ans;
	int cost=0,ptr=1;;
	int a[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=1e9 ;i++){
		if(ptr<=n && a[ptr]==i){
			ptr++;
			continue;
		}
		if(cost+i>m){
			break;
		}
		ans.push_back(i);
		cost+=i;
	}
	cout << ans.size() << endl;
	bool first=true;
	for(int i=0; i<ans.size() ;i++){
		if(first){
			cout << ans[i];
			first=false;
		}
		else{
			cout << ' ' << ans[i];
		}
	}
	cout << endl;
}