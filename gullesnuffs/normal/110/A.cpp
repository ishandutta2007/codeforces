#include <iostream>

using namespace std;

int main()
{
	int x=0;
	long long n;
	cin >> n;
	while(n > 0){
		if(n % 10 == 4 || n % 10 == 7)++x;
		n /= 10;
	}
	if(x == 0){
		cout << "NO";
		return 0;
	}
	while(x > 0){
		if(x % 10 != 4 && x % 10 != 7){
			cout << "NO";
			return 0;
		}
		x /= 10;
	}
	cout << "YES";
	return 0;
}