#include<iostream>
using namespace std;
int main(){
	int x,y;
	cin >> x >> y;
	int ans=0;
	if((x-y)%3==0 && (x!=1 || y!=1)){
		cout << x+y-3 << endl;
	}
	else{
		cout << x+y-2 << endl;
	}
}