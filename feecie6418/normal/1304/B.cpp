#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
string a[105];
int n,m,mch[105],s=0,x[105];
bool isp[105];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++) {
		if(mch[i])continue;
		for(int j=i+1; j<=n; j++) {
			string tmp=a[j];
			reverse(tmp.begin(),tmp.end());
			if(tmp==a[i])mch[i]=j,mch[j]=i,s++;
		}
	}
	for(int i=1; i<=n; i++) {
		string tmp=a[i];
		reverse(tmp.begin(),tmp.end());
		if(tmp==a[i]) {
			if(!mch[i]) {
				cout<<s*m*2+m<<endl;
				for(int j=1; j<=n; j++) {
					if(mch[j]&&mch[j]>j)cout<<a[j],x[++x[0]]=mch[j];
				}
				cout<<a[i];
				for(int j=x[0]; j>=1; j--) {
					cout<<a[x[j]];
				}
				return 0;
			}
		}
	}
	cout<<s*m*2<<endl;
	for(int j=1; j<=n; j++) {
		if(mch[j]&&mch[j]>j)cout<<a[j],x[++x[0]]=mch[j];
	}
	for(int j=x[0]; j>=1; j--) {
		cout<<a[x[j]];
	}
	return 0;
}