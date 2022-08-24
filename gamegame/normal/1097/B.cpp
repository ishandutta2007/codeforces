#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int a[16];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n ;i++) cin >> a[i];
	for(int i=0; i<(1<<n) ;i++){
		int cur=0;
		for(int j=0; j<n ;j++){
			if(i&(1<<j)) cur-=a[j];
			else cur+=a[j];
		}
		if(cur%360==0){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}