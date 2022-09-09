#include<bits/stdc++.h>
using namespace std;
#define maxn 320000
int main(){
	int n, x, y;
	cin >> n >> x >> y;
	if(x > y) cout << n;
	else{
		int a, s = 0;
		while(n --){
			cin >> a;
			s += a <= x;
		}
		cout << (s + 1) / 2;
	}
}