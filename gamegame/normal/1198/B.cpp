#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[200001];
int b[200001];
int t[200001],p[200001],v[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		b[i]=-1;
	}
	cin >> q;
	for(int i=1; i<=q ;i++){
		cin >> t[i];
		if(t[i]==1) cin >> p[i];
		cin >> v[i];
	}
	int mx=0;
	for(int i=q; i>=1 ;i--){
		if(t[i]==2){
			mx=max(mx,v[i]);
			continue;
		}
		if(b[p[i]]!=-1) continue;
		b[p[i]]=max(mx,v[i]);
	}
	for(int i=1; i<=n ;i++) if(b[i]==-1) b[i]=max(mx,a[i]);
	for(int i=1; i<=n ;i++) cout << b[i] << ' ';
	cout << endl;
}