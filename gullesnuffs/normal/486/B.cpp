#include <bits/stdc++.h>

using namespace std;

int a[105][105];
int b[105][105];

int main(){
	int m, n;
	cin >> m;
	cin >> n;
	for(int i=0; i < m; ++i)
		for(int j=0; j < n; ++j)
			cin >> a[i][j];
	for(int i=0; i < m; ++i)
		for(int j=0; j < n; ++j){
			b[i][j]=1;
			for(int k=0; k < m; ++k)
				if(!a[k][j])
					b[i][j]=0;
			for(int k=0; k < n; ++k)
				if(!a[i][k])
					b[i][j]=0;
		}
	for(int i=0; i < m; ++i)
		for(int j=0; j < n; ++j){
			bool ok=0;
			for(int k=0; k < m; ++k)
				if(b[k][j])
					ok=1;
			for(int k=0; k < n; ++k)
				if(b[i][k])
					ok=1;
			if(ok != a[i][j]){
				cout << "NO" << endl;
				return 0;
			}

		}
	cout << "YES" << endl;
	for(int i=0; i < m; ++i){
		for(int j=0; j < n; ++j){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}