#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, m, s; cin>>n>>m>>s;
	long long ans=0;
	for(int tx1=1; tx1<=n; tx1+=2)
		for(int tx2=1; tx2<=n; tx2+=2) {
			int x1=tx1, x2=tx2;
			if(x1<x2) swap(x1, x2);
			for(int y1=1; y1<=m; y1+=2) {
				int rest=s-x1*y1;
				if(rest<0) break;
				if(rest==0)
					ans+=(n-x1+1)*(m-y1+1)*(y1+1)/2;
				else
					if(rest%(x2*2)==0) {
						int y2=y1+rest/x2;
						if(y2<=m)
							ans+=(n-x1+1)*(m-y2+1);
					}
			}
		}
	cout<<ans<<endl;
	return 0;
}