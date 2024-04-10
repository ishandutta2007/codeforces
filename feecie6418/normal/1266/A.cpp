#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[105];
int n;
void Solve(){
	cin>>a+1,n=strlen(a+1);
	int sum=0,even=0,zero=0;
	for(int i=1;i<=n;i++)sum+=(a[i]-'0')%3,even+=a[i]!='0'&&a[i]%2==0,zero+=a[i]=='0';
	if(sum%3!=0||!zero)return puts("cyan"),void();
	if(zero==1&&!even)return puts("cyan"),void();
	puts("red");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}