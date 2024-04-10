#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	queue<int>ans;
	for(int i=1; i<=n ;i++){
		if(m>=i*2-1+n*2){
			ans.push(i*2-1+n*2);
		}
		if(m>=i*2-1){
			ans.push(i*2-1);
		}
		if(m>=i*2+n*2){
			ans.push(i*2+n*2);
		}
		if(m>=i*2){
			ans.push(i*2);
		}
	}
	while(ans.size()>1){
		cout << ans.front() << ' ';
		ans.pop();
	}
	cout << ans.front() << endl;
}