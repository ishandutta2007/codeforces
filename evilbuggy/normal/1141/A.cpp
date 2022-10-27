#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ll n, m;
	cin>>n>>m;
	ll z = (m/n);
	int cnt = 0;
	while(z%2 == 0){
		z /= 2;
		cnt++;
	}
	while(z%3 == 0){
		z /= 3;
		cnt++;
	}
	if(z == 1 && m%n == 0)cout<<cnt<<endl;
	else cout<<-1<<endl;
}