#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010;
int n,k;
void qry(int now) {
	cout<<"? "<<now<<endl;
	int x;
	cin>>x;
	if(x==k)return;
	while(1) {
		if(x<k)now=now%n+1;
		else now=(now+n-2)%n+1;
		cout<<"? "<<now<<endl;
		cin>>x;
		if(x==k) {
			cout<<"! "<<now<<endl;
			exit(0);
		}
	}
}
signed main() {
	cin>>n>>k;
	int now=1;
	qry(1);
	for(int i=1;;i++) {
		qry(now);
		now+=i;
	}
	return 0;
}