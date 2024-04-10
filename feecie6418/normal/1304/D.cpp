#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[200005];
int main() {
	int T,n;
	cin>>T;
	while(T--) {
		cin>>n>>str+1;
		int now=n;
		for(int i=1;i<n;i++){
			if(str[i]=='>')cout<<now--<<' ';
			else {
				int j=i;
				while(str[j]=='<')j++;
			//	cout<<"P:\n"<<i<<' '<<j<<'\n';
				for(int k=now-(j-i);k<=now;k++)cout<<k<<' ';
				now-=j-i+1;
				i=j;
			}
		}
		if(now)cout<<now;
		cout<<endl;
		now=1;
		for(int i=1;i<n;i++){
			if(str[i]=='<')cout<<now++<<' ';
			else {
				int j=i;
				while(str[j]=='>')j++;
				for(int k=now+(j-i);k>=now;k--)cout<<k<<' ';
				now+=j-i+1;
				i=j;
			}
		}
		if(now<=n)cout<<now;
		cout<<endl;
	}
	return 0;
}