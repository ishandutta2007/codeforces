#include<bits/stdc++.h>
using namespace std;
const int N=1510;
int f[N];
int main() {
	int n,k,h,P=1,S=1,x,y;
	scanf("%d%d",&n,&k);
	char s[10];
	for(h=1;S<n;S+=P*k,P*=k,h++);
	while(1) {
		x=rand()%n+1,y=rand()%n+1;
		if(x==y)continue;
		int sum=0;
		for(int i=1;i<=n;i++) {
			if(i==x||i==y)continue;
			cout<<"? "<<x<<' '<<i<<' '<<y<<endl;
			cin>>s;
			if(s[0]=='Y')sum++,f[i]=1;
			else f[i]=0;
		}
		if(sum==2*h-3)break;
	}
	for(int i=1;i<=n;i++) {
		if(i==x||i==y)continue;
		if(f[i]==1) {
			int cnt=0;
			for(int j=1;j<=n;j++) {
				if(j==i||j==x||j==y)continue;
				if(!f[j])continue;
				cout<<"? "<<x<<' '<<j<<' '<<i<<endl;
				cin>>s;
				if(s[0]=='Y')cnt++;
			}
			if(cnt==h-2) {
				cout<<"! "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}