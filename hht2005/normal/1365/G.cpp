#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int id[N];
long long w[14];
int calc(int x) {
	int c=0;
	while(x) {
		c++;
		x-=x&-x;
	}
	return c;
}
int main() {
	int cnt=0,n;
	for(int i=(1<<6)-1;i<(1<<13)-1;i++)
		if(calc(i)==6)id[++cnt]=i;
	scanf("%d",&n);
	for(int i=0;i<13;i++) {
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(id[j]>>i&1)cnt++;
		if(!cnt)continue;
		cout<<"? "<<cnt;
		for(int j=1;j<=n;j++)
			if(id[j]>>i&1)cout<<' '<<j;
		cout<<endl;
		cin>>w[i];
	}
	cout<<"!";
	for(int i=1;i<=n;i++) {
		long long S=0;
		for(int j=0;j<13;j++)
			if(!(id[i]>>j&1))S|=w[j];
		cout<<' '<<S;
	}
	cout<<endl;
	return 0;
}