#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int n, b[4444], t, last[4444], a[4444][4444], c[4444], m, d[4444];
map<int, int> k;
int main(){
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> b[i];
		if (!k[b[i]]) k[b[i]]=i;
		b[i]=k[b[i]];
	}
	for (int i=1; i<=n; i++) {
		for (int j=last[b[i]]+1; j<i; j++) if (!d[b[j]]) d[b[j]]=1, a[b[i]][b[j]]+=2;
		for (int j=last[b[i]]+1; j<i; j++) d[b[j]]=0;
		last[b[i]]=i;
		c[b[i]]++;
	}
	for (int i=1; i<=n; i++) if (last[i]) {
		for (int j=last[i]+1; j<=n; j++) if (!d[b[j]]) d[b[j]]=1, a[i][b[j]]+=1;
		for (int j=last[i]+1; j<=n; j++) d[b[j]]=0;
	}
	for (int i=1; i<=n; i++) if (c[i]>m) m=c[i];
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) if (i!=j&&a[i][j]>m) m=a[i][j];
	cout << m;
    return 0;
}