#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <array>
#include <cmath>
using namespace std;

	int gcd (int a, int b){
		if ((a==0)||(b==0)) return a+b;
		else return gcd(max(a, b)%min(a,b), min(a,b));
	}

int main (){

	int a, b;
	cin >> a >> b;
	int d;
	d = gcd(a, b);
	a = a/d;
	b = b/d;
	int k=0;
	while (a%2==0){
		k++;
		a=a/2;
	}
	while (a%3==0){
		k++;
		a=a/3;
	}
	while (a%5==0){
		k++;
		a=a/5;
	}
	if (a!=1) cout << -1;
	else {
	while (b%2==0){
		k++;
		b=b/2;
	}
	while (b%3==0){
		k++;
		b=b/3;
	}
	while (b%5==0){
		k++;
		b=b/5;
	}
	if (b!=1) cout << -1;
	else cout << k;
	}
	return(0);


}