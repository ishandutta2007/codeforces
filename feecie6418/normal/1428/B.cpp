#include<bits/stdc++.h>
using namespace std;
int t,is[300005];
char str[300005];
int main(){
	cin>>t;
	while(t--){
		int n,flag1=1,flag2=1;
		cin>>n>>str+1;
		for(int i=1;i<=n;i++)if(str[i]=='>')flag1=0;
		for(int i=1;i<=n;i++)if(str[i]=='<')flag2=0;
		if(flag1||flag2){
			cout<<n<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)if(str[i]=='-')is[i-1]=is[i%n]=1;
		int s=0;
		for(int i=0;i<n;i++)if(is[i])s++;
		cout<<s<<endl;
		for(int i=0;i<n;i++)is[i]=0;
	}
	return 0;
}