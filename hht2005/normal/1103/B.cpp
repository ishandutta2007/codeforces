#include<bits/stdc++.h>
using namespace std;
int main() {
	string S;
	cin>>S;
	while(S!="end") {
		int l=0,r=1;
		while(1) {
			cout<<"? "<<l<<' '<<r<<endl;
			cin>>S;
			if(S=="x")break;
			l=r;
			r=l+l;
		}
		while(l+1<r) {
			int mid=(l+r)>>1;
			cout<<"? "<<mid<<' '<<l<<endl;
			cin>>S;
			if(S=="x")l=mid;
			else r=mid;
		}
		cout<<"! "<<l+1<<endl;
		cin>>S;
	}
	return 0;
}