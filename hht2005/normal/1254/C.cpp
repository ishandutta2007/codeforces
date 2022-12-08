#include<bits/stdc++.h>
using namespace std;
const int N=1010;
long long d[N];
int L[N],R[N];
int cmp(int a,int b) {
	return d[a]<d[b];
}
signed main() {
	int n;
	cin>>n;
	int a=1,b=2,x;
	for(int i=3;i<=n;i++) {
		cout<<"2 "<<a<<' '<<b<<' '<<i<<endl;
		cin>>x;
		if(x<0)b=i;
	}
	int c=0,l=0,r=0;
	for(int i=1;i<=n;i++) {
		if(a==i||b==i)continue;
		cout<<"1 "<<i<<' '<<a<<' '<<b<<endl;
		cin>>d[i];
		if(d[c]<d[i])c=i;
	}
	for(int i=1;i<=n;i++) {
		if(a==i||b==i||c==i)continue;
		cout<<"2 "<<a<<' '<<c<<' '<<i<<endl;
		cin>>x;
		if(x>0)L[++l]=i;
		else R[++r]=i;
	}
	sort(L+1,L+l+1,cmp);
	sort(R+1,R+r+1,cmp);
	cout<<"0";
	cout<<' '<<a;
	cout<<' '<<b;
	for(int i=1;i<=r;i++)
		cout<<' '<<R[i];
	cout<<' '<<c;
	for(int i=l;i>=1;i--)
		cout<<' '<<L[i];
	cout<<endl;
	return 0;
}