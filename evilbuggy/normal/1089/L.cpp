#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, k;
	cin>>n>>k;

	int a[n+1], b[n+1], c[k+1];
	int cnt = k;
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(c[a[i]] == 0){
			cnt--;
			c[a[i]] = 1;
		}

	}
	for(int i = 1; i <= n; i++){
		cin>>b[i];
	}
	vector<int> arr[k+1];
	for(int i = 1; i <= n; i++){
		arr[a[i]].push_back(b[i]);
	}
	priority_queue<int, vector<int>, greater<int> > pq; 
	for(int i = 1; i <= k; i++){
		sort(arr[i].rbegin(), arr[i].rend());
		for(int j = 1; j < arr[i].size(); j++){
			pq.push(arr[i][j]);
		}
	}
	long long int ans = 0;
	while(cnt--){
		int y = pq.top();
		pq.pop();
		ans += y;
	}
	cout<<ans<<endl;

}