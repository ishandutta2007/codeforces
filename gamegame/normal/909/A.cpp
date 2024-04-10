#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	string u,v;
	cin >> u >> v;
	string ans=u+v;
	for(int i=0; i<u.size() ;i++){
		for(int j=0; j<v.size() ;j++){
			string newi=u.substr(0,i+1)+v.substr(0,j+1);
			ans=min(ans,newi);
		}
	}
	cout << ans << endl;
}