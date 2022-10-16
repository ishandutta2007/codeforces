#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false),cin.tie(0);
	int n,k;
	cin >> n>>k;
	int mas[n];
	for(int i = 0;i<n;i++)
	    cin >> mas[i];
	int c=0;
	for(int i = 0;i<n;i++){
	    c+=mas[i]>=mas[k-1] and mas[i]>0;
	}
	cout << c;
	return 0;
}