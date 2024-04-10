#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int n; int x[111], y[111];
bool c[111];

void vis(int k) {
	c[k]=true;
	for(int i=1; i<=n; ++i)
		if(!c[i] && (x[i]==x[k] || y[i]==y[k]))
			vis(i);
}

int main() {
	cin>>n; for(int i=1; i<=n; ++i) cin>>x[i]>>y[i];
	memset(c, false, sizeof(c));
	int cnt=0;
	while(1) {
		int k=0; for(int i=1; i<=n; ++i) if(!c[i]) k=i;
		if(k==0) break;
		++cnt; vis(k);
	}
	cout<<(cnt-1)<<endl;
	return 0;
}