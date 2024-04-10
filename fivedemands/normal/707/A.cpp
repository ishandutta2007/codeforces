#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m;
	char c;
	for(int i=1; i<=n ;i++){
		for(int i=1; i<=m ;i++){
			cin >> c;
			if(c=='C' || c=='M' || c=='Y'){
				cout << "#Color\n";
				return 0;
			}
		}
	}
	cout << "#Black&White\n";
}