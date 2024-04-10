#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[3];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;cnt[x]++;
	}
	if(cnt[1]==0){
		for(int i=1; i<=n ;i++) cout << "2 ";
		return 0;
	}
	if(cnt[2]==0){
		for(int i=1; i<=n ;i++) cout << "1 ";
		return 0;
	}
	cout << "2 1 ";
	for(int i=1; i<cnt[2] ;i++) cout << "2 ";
	for(int i=1; i<cnt[1] ;i++) cout << "1 ";
	
}