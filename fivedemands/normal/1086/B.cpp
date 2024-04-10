#include<iostream>
#include<iomanip>
using namespace std;
int deg[100001];
int n;
double s;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for(int i=1; i<n ;i++){
		int u,v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	int cnt=0;
	for(int i=1; i<=n ;i++) if(deg[i]==1) cnt++;
	cout << fixed << setprecision(20) << 2*s/cnt << endl;
}