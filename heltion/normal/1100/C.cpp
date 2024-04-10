#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, r;
	cin >> n >> r;
	cout << setprecision(8) << r /(1 - sin(acos(-1) / n)) - r;
}