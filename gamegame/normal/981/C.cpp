#include<iostream>
using namespace std;
string s;
int n;
int deg[100001];
int main(){
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	int mid=0;
	for(int i=1; i<=n ;i++){
		if(deg[i]>2){
			if(mid!=0){
				cout << "No\n";
				return 0;
			}
			mid=i;
		}
	}
	if(mid==0) mid=1;
	cout << "Yes\n";
	int cnt=0;
	for(int i=1; i<=n ;i++){
		if(i!=mid && deg[i]==1) cnt++;
	}
	cout << cnt << endl;
	for(int i=1; i<=n ;i++){
		if(i!=mid && deg[i]==1) cout << mid << ' ' << i << endl;
	}
}