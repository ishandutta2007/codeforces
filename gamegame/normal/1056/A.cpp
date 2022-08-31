#include<iostream>
using namespace std;
int cnt[101];
int n,r;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> r;
		for(int j=1; j<=r ;j++){
			int x;
			cin >> x;
			cnt[x]++;
		}
	}
	for(int i=1; i<=100 ;i++){
		if(cnt[i]==n) cout << i << ' ';
	}
}