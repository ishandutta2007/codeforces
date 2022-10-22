#include <bits/stdc++.h>

using namespace std;

int main(){
	long long x[2], y[2];
	for(int i=0; i < 2; ++i)
		cin >> x[i] >> y[i];
	int n;
	cin >> n;
	int ans=0;
	for(int i=0; i < n; ++i){
		long long a, b, c;
		cin >> a >> b >> c;
		int d[2];
		for(int j=0; j < 2; ++j){
			if(a*x[j]+b*y[j]+c > 0)
				d[j]=1;
			else
				d[j]=0;
		}
		if(d[0] != d[1])
			++ans;
	}
	cout << ans << endl;
}