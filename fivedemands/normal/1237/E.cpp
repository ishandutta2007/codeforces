#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[1000001];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int cur=1;
	for(int i=1; cur<=n ;i++){
		ans[cur]=1;
		if(i%2==1) cur++;
		else if(i%4==0) cur=cur*2-1;
		else cur=cur*2;
	}
	cout << ans[n] << endl;
}