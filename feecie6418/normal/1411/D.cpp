#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,s1[100005],s0[100005],sa[100005];
ll ans=1e18,a,b,pre[100005][2],suf[100005][2];
char str[100005];
int main() {
	cin>>str+1>>a>>b,n=strlen(str+1);
	for(int i=1;i<=n;i++)s1[i]=s1[i-1]+(str[i]=='1'),s0[i]=s0[i-1]+(str[i]=='0'),sa[i]=sa[i-1]+(str[i]=='?');
	for(int i=1;i<=n;i++){
		pre[i][0]=pre[i-1][0];
		pre[i][1]=pre[i-1][1];
		if(str[i]=='1')pre[i][1]+=a*s0[i-1],pre[i][0]+=a*(i-1-s1[i-1]);
		if(str[i]=='0')pre[i][0]+=b*s1[i-1],pre[i][1]+=b*(i-1-s0[i-1]);
		if(str[i]=='?'){
			pre[i][1]+=a*s0[i-1];
			pre[i][0]+=b*s1[i-1];
		}
		//cout<<pre[i][0]<<' '<<pre[i][1]<<endl;
	}
	for(int i=n;i>=1;i--){
		suf[i][0]=suf[i+1][0];
		suf[i][1]=suf[i+1][1];
		if(str[i]=='0')suf[i][0]+=a*(s1[n]-s1[i]),suf[i][1]+=a*(n-i-s0[n]+s0[i]);
		if(str[i]=='1')suf[i][1]+=b*(s0[n]-s0[i]),suf[i][0]+=b*(n-i-s1[n]+s1[i]);
		if(str[i]=='?'){
			suf[i][0]+=a*(s1[n]-s1[i]);
			suf[i][1]+=b*(s0[n]-s0[i]);
		}
		//cout<<suf[i][0]<<' '<<suf[i][1]<<endl;
	}
	for(int i=0;i<n;i++){
		ans=min(ans,a*(i-s1[i])*(n-i-s0[n]+s0[i])+b*s1[i]*(s0[n]-s0[i])+pre[i][0]+suf[i+1][1]);
		ans=min(ans,a*s0[i]*(s1[n]-s1[i])+b*(i-s0[i])*(n-i-s1[n]+s1[i])+pre[i][1]+suf[i+1][0]);
		//cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}