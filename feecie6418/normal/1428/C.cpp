#include<bits/stdc++.h>
using namespace std;
int t,n;
char str[300005];
int main(){
	cin>>t;
	while(t--){
		int n,ans=0,c=0;
		cin>>str+1;
		n=strlen(str+1);
		for(int i=n;i>=1;i--){
			if(str[i]=='B')c++;
			else if(c)c--;
			else ans++;
		}
		cout<<ans+(c%2)<<endl;
	}
	return 0;
}