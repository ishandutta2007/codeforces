#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int f[maxn],t[maxn],v[maxn];
int main() {
	int n,pre=-1,now=-1;
	cin>>n;
	for(int i=2;i<=n;i++) {
		cout<<"XOR 1 "<<i<<endl;
		cin>>f[i];
		if(now!=-1)continue;
		if(f[i]==0) {
			now=i;
			pre=1;
		}
		if(t[f[i]]) {
			now=i;
			pre=t[f[i]];
		}
		t[f[i]]=i;
	}
	if(pre!=-1) {
		cout<<"OR "<<pre<<' '<<now<<endl;
		cin>>v[pre];
		v[now]=v[pre];
		for(int i=1;i<=n;i++)
			v[i]=v[now]^f[i]^f[now];
		cout<<"!";
		for(int i=1;i<=n;i++)
			cout<<' '<<v[i];
		cout<<endl;
		return 0;
	}
	int F1=-1,F2=-1;
	for(int i=2;i<=n;i++)
		if(f[i]==1) {
			cout<<"AND 1 "<<i<<endl;
			cin>>F1;
		} else if(f[i]==2) {
			cout<<"AND 1 "<<i<<endl;
			cin>>F2;
		}
	if(F2&1)F1|=1;
	v[1]=F1;
	for(int i=2;i<=n;i++)
		v[i]=v[1]^f[i];
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<' '<<v[i];
	cout<<endl;
	return 0;
}