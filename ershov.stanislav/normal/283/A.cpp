#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair

int a[222222], l, n;
long long sum;

int main() {
	cin >> n;
	cout << fixed << setprecision(10);
	l=1;
	for (int i=0; i<n; i++) {
		int t, x, k;
		cin >> t;
		if (t==1) {
			cin >> k >> x;
			a[k-1]+=x;
			sum+=k*x;
			cout << ((double)sum)/l << endl;
		} else if (t==2) {
			cin >> k;
			a[l-1]-=k;
			a[l]=k;
			l++;
			sum+=k;
			cout << ((double)sum)/l << endl;
		} else {
			l--;
			a[l-1]+=a[l];
			sum-=a[l];
			a[l]=0;
			cout << ((double)sum)/l << endl;
		}
	}
}