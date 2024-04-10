#include<bits/stdc++.h>
using namespace std;
vector<int>v[2001];
int a[2001];
vector<int>b;
int n,m;
int c=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		a[i]=x;
		if(x<=m) v[x].push_back(i);
		else b.push_back(i);
	}
	int k=n/m;
	for(int i=1; i<=m ;i++){
		if(v[i].size()>=k){
			for(int j=k; j<v[i].size() ;j++) b.push_back(v[i][j]);
		}
	}
	for(int i=1; i<=m ;i++){
		if(v[i].size()<k){
			for(int x=0; x<k-v[i].size() ;x++){
				a[b.back()]=i;
				b.pop_back();
				c++;
			}
		}
	}
	cout << k << ' ' << c << endl;
	for(int i=1; i<=n ;i++) cout << a[i] << ' ';
	cout << endl;
}