#include <iostream>
#include <cstring>

using namespace std;
int n, a[3], x;
int main(){
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		a[i%3]+=x;
	}
	x=max(a[0], max(a[1], a[2]));
	if (x==a[0]) cout << "chest";
	else if (x==a[1]) cout << "biceps";
	else if (x==a[2]) cout << "back";
    return 0;
}