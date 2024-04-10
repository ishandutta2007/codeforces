#include <bits/stdc++.h>

using namespace std;

int n;
long double vb, vs;
int x[105];
long double ux, uy;
int main(){
	cin >> n >> vb >> vs;
	for(int i=0; i < n; ++i)
		scanf("%d", x+i);
	cin >> ux >> uy;
	long double ans=999999999;
	int best=-1;
	for(int i=1; i < n; ++i){
		long double dx=ux-x[i];
		long double dis = x[i]/vb + sqrt(dx*dx+uy*uy)/vs;
		if(dis <= ans+1e-10F){
			ans=dis;
			best=i+1;
		}
	}
	cout << best << endl;
}