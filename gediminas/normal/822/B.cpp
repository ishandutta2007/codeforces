/*input
4 10
abcd
ebceabazcd

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,m;
	cin >> n >> m;
	string a,b;
	cin >> a >> b;
	vector<int> ats;
	for(int i = 0; i < n; i++) {
		ats.push_back(i+1);
	}
	for(int i = 0;i+n<=m;i++){
		vector<int> ats1;
		for(int j = 0; j < n; j++) {
			if(a[j]!=b[i+j])
				ats1.push_back(j+1);
		}
		if(ats.size()>ats1.size())
			ats=ats1;
	}

	cout << ats.size() << endl;
	for(auto&& i : ats) {
		cout << i << " ";
	}


	return 0;
}