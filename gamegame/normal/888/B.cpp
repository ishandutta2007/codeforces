#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int x=0,y=0;
	for(int i=1; i<=n ;i++){
		char c;
		cin >> c;
		if(c=='U') y++;
		else if(c=='R') x++;
		else if(c=='L') x--;
		else y--;
	}
	cout << n-abs(x)-abs(y) << endl;
}