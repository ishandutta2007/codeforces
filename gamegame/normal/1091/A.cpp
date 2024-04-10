#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int y,b,r;
	cin >> y >> b >> r;
	int num=min(y,b-1);
	 num=min(num,r-2);
	 cout << num*3+3 << endl;
}