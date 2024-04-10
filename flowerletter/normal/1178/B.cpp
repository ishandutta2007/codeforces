#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int sum[1000010],n;
unsigned long long ans=0;
int main(){
	cin>>s+1;n=strlen(s+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1];
		if(s[i]=='v' && s[i-1]=='v') sum[i]++;
	}
		
	for(int i=1;i<=n;i++){
		if(s[i]=='o'){
			long long a=sum[i],b=sum[n]-sum[i];
			ans+=a*b;
		}
	} 
	cout<<ans;
	return 0;
}