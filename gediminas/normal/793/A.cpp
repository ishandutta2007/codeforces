/*input

4 1
1 1000000000 1000000000 1000000000
*/
#include <iostream>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	long long mi = 1e10;

	int n, k;
	cin >> n >> k;

	long long mas[n];

	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		mi = min(mi, mas[i]);
	}

	long long ats = 0;

	for (int i = 0; i < n; i++) {
		if((mas[i]-mi)%k!=0){
			cout << -1;
			return 0;
		}
		ats+=(mas[i]-mi)/k;
	}

	cout << ats << endl;
	return 0;
}