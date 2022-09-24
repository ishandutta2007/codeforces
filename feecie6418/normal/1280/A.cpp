#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int len,x,cur;
char a[1000005]; 
void Solve(){
	cin>>x>>a+1,len=strlen(a+1),cur=len;
	for(int i=1;i<=x;i++){
		int w=(len-i+mod)%mod;
		len=(i+1ll*w*(a[i]-'0'))%mod;
		int t=a[i]-'1';
		for(int j=1,r=cur;j<=t;j++){
			int p=i+1;
			while(cur<x&&p<=r)a[++cur]=a[p],p++;
		}
	}
	cout<<len<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}