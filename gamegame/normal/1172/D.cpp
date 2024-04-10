#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[1001],c[1001];
int pr[1001],pc[1001];
int pos[1001];
int a[1001][1001];
int k[1001];
int ax[2001],ay[2001],bx[2001],by[2001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> r[i];
	for(int i=1; i<=n ;i++) cin >> c[i];
	for(int i=1; i<=n ;i++) pr[r[i]]=i;
	for(int i=1; i<=n ;i++) pc[c[i]]=i;
	for(int i=1; i<=n ;i++){
		if(r[i]==i && c[i]==i) continue;
		++m;
		ax[m]=pr[i];by[m]=pc[i];ay[m]=bx[m]=i;
		int x=pr[i];
		swap(pr[i],pr[r[i]]);
		swap(r[i],r[x]);
		x=pc[i];
		swap(pc[i],pc[c[i]]);
		swap(c[i],c[x]);
	}
	cout << m << endl;
	for(int i=1; i<=m ;i++){
		cout << ax[i] << ' ' << ay[i] << ' ' << bx[i] << ' ' << by[i] << endl;
	}
}