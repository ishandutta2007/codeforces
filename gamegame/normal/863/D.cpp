#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int n,q,m;
int a[200001];
int t[200001],l[200001],r[200001];
int b[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=q ;i++){
		cin >> t[i] >> l[i] >> r[i];
	}
	for(int i=1; i<=m ;i++){
		cin >> b[i];
		for(int j=q; j>=1 ;j--){
			if(r[j]<b[i] || l[j]>b[i]) continue;
			if(t[j]==1){
				if(b[i]==l[j]) b[i]=r[j];
				else b[i]--;
			}
			else{
				b[i]=l[j]+r[j]-b[i];
			}
		}
		cout << a[b[i]] << ' ';
	}
}