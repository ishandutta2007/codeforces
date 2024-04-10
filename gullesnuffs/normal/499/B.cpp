#include <bits/stdc++.h>

using namespace std;

map<string, string> M;

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i < m; ++i){
		string a, b;
		cin >> a >> b;
		if(b.size() < a.size())
			M[a]=b;
		else
			M[a]=a;
	}
	for(int i=0; i < n; ++i){
		string c;
		cin >> c;
		cout << M[c] << " ";
	}
	cout << endl;
}