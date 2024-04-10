/*input
1 1 3 6
1 5
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
	long long a,b,c,d,e,f;
	cin >> a >> b>>c>>d>>e>>f;
	cout << ((a-c)%e==0 and (b-d)%f==0 and abs((a-c)/e)%2==abs((b-d)/f)%2?"YES":"NO");


	return 0;
}