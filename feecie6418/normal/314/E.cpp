#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
ui f[50005],n;
char a[100005];
int main(){
	cin>>n>>a+1,f[0]=1;
	if(n&1)return cout<<0,0;
	for(int i=1;i<=n;i++){
		if(a[i]=='?'){
			for(int j=i/2;j;j--)f[j]=f[j]*25+f[j-1];
			f[0]*=25;
		}
	}
	cout<<f[n/2];
}