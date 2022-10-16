/*input
4
1 5 4 7
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
	
	int n;
	cin >> n;
	long long a[n];
	long long skir[n];
	skir[0]=0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<n;i++){
		skir[i]=labs(a[i]-a[i-1]);
	}
	long long mi=0, ma=0;
	long long temp=0;
	int dg=1;
	for(int i = 0;i<n;i++){
		temp+=skir[i]*dg;
		dg*=-1;
		mi=min(mi,temp);
		ma=max(ma,temp);
	}
	long long ats = ma-mi;
	mi=0, ma=0;
	temp=0;
	dg=-1;
	for(int i = 0;i<n;i++){
		temp+=skir[i]*dg;
		dg*=-1;
		mi=min(mi,temp);
		ma=max(ma,temp);
	}
	cout << max(ats,ma-mi);

	return 0;
}