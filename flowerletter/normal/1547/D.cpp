#include <iostream>
using namespace std;
int a[300000];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int lst=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			cout << (a[i]|a[i-1])-a[i] << " ";
			a[i]=a[i]|a[i-1];
		}
		cout << endl;
	}
	return 0;
}
//
//
// 
//aiai-1
//
//
//ai-1ai
//a[i]|=a[i-1] 
//
// a[i]=a[i]|a[i-1] 
// 
//RE 
//n<=200000
//
// 300000