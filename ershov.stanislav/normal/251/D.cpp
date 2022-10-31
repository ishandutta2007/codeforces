#include <iostream>
#include <bitset>

using namespace std;
#define N 111111
typedef long long ll;
bitset<N> a[80];
ll x=0, c, n, l, m, d[70], b[N], t, p;
int main()
{
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> c;
		x^=c;
		for (int j=0; j<63; j++) a[62-j][i] = (c&(1ll<<j))>0;
	}
	for (int i=0; i<63; i++) if (~x&(1ll<<(62-i))) {
		a[69]=a[i];
		for (int j=i; j>l; j--) a[j]=a[j-1];
		a[l++]=a[69];
	}
	for (int i=0; i<63; i++) {
		a[i][n]=1;
		for (int j=0; j<t; j++) if (a[i][d[j]]) a[i]^=a[j];
		for (p=0; p<n&&!a[i][p]; p++);
		if (p==n) a[i][n]=0;
		else {
			for (int j=0; j<t; j++) if (a[j][p]) a[j]^=a[i];
			d[t]=p,swap(a[t++], a[i]);
		}
	}
	while (t>0) t--, b[d[t]]=a[t][n];
	for (int i=0; i<n; i++) cout << (b[i]?'2':'1') << ' ';
	return 0;
}