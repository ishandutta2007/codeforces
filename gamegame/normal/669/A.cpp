#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << (n/3)*2+(n%3!=0) << endl;
}