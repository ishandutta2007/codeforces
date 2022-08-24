#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
void solve1(int n){
	if(n%2==1){
		cout << "NO\n";
		return;
	}
	if(n==0){
		cout << "YES\n";
		return;
	}
	int m=n;
	while(m!=(m&-m)) m-=(m&-m);
	int sn=n-(n-m+1)*2;
	solve1(sn);
	for(int i=n; i>sn ;i--){
		cout << i << ' ';
	}
}
void solve2(int n){
	if(n%2==1 && n<=5){
		cout << "NO\n";
		return;
	}
	if(n%2==0 && n<6){
		cout << "NO\n";
		return;
	}
	if(n==6){
		cout << "YES\n3 6 2 5 1 4 ";
		return;
	}
	if(n==7){
		cout << "YES\n3 6 2 5 7 4 1 ";
		return;
	}
	if(n%2==1){
		solve2(n-2);
		cout << n << ' ' << n-1 << ' ';
		return;
	}
	int m=n;
	while(m!=(m&-m)) m-=(m&-m);
	if(m==n){
		cout << "NO\n";
		return;
	}
	solve2(m-2);
	cout << n << ' ';
	for(int i=m; i<n ;i++){
		cout << (i^1) << ' ';
	}
	cout << m-1 << ' ';
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	solve1(n);
	cout << endl;
	solve2(n);
	cout << endl;
}