/*input
3 2
2 3 4
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int ats=0;
	for(int i = 0;i<n;i++){
		int x;
		cin >> x;
		ats+=x/k;
		if(x%k!=0)
			ats++;
	}

	cout << ats/2+ats%2;

	return 0;
}