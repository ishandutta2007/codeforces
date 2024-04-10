#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m;
int main(){
	cin >> n >> m;
	m=min(n,m);
	n-=m;
	long long cur=(long long)sqrt(n*2);
	if(cur*(cur+1)/2<n) cur++;
	cout << m+cur << '\n';
}