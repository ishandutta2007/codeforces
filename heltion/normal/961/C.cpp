#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}
int a[4][2]={};
int main(){
	int n=read();
	for(int fxxk=0;fxxk<4;fxxk++){
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			int mtz=0;
			for(int j=0;j<n;j++)if(s[j]-'0'==(i+j)%2)mtz++;
			a[fxxk][0]+=mtz;
			a[fxxk][1]+=n-mtz;
		}
	}
	int ans=1000000;
	ans=min(ans,a[0][0]+a[1][0]+a[2][1]+a[3][1]);
	ans=min(ans,a[0][0]+a[1][1]+a[2][0]+a[3][1]);
	ans=min(ans,a[0][0]+a[1][1]+a[2][1]+a[3][0]);
	ans=min(ans,a[0][1]+a[1][0]+a[2][1]+a[3][0]);
	ans=min(ans,a[0][1]+a[1][0]+a[2][0]+a[3][1]);
	ans=min(ans,a[0][1]+a[1][1]+a[2][0]+a[3][0]);
	printf("%d",ans);
}