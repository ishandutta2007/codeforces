#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pr;
const int mod=1e9+7,B=233;
int n,m,hsh[1000005],pw[1000005];
char a[100005],s[1000005];
pr operator +(pr x,pr y){
	return pr((1ll*pw[y.second]*x.first+y.first)%mod,x.second+y.second);
}
pr Get(int l,int r){
	return pr((hsh[r]-1ll*hsh[l-1]*pw[r-l+1]%mod+mod)%mod,r-l+1);
}
int main(){
	cin>>a+1>>s+1,pw[0]=1,n=strlen(a+1),m=strlen(s+1);
	for(int i=1;i<=m;i++)pw[i]=1ll*pw[i-1]*B%mod,hsh[i]=(1ll*hsh[i-1]*B+s[i])%mod;
	int c0=0,c1=0,ans=0;
	for(int i=1;i<=n;i++)c0+=a[i]=='0',c1+=a[i]=='1';
	for(int i=1;i<=m;i++){
		if(1ll*i*c0>=m||(m-1ll*i*c0)%c1)continue;
		int j=(m-1ll*i*c0)/c1,l=1,ok=1;
		pr t0=pr(0,0),t1=pr(0,0);
		for(int k=1;k<=n;k++){
			if(a[k]=='0'){
				if(!t0.second)t0=Get(l,l+i-1);
				else if(t0!=Get(l,l+i-1))ok=0;
				l+=i;
			}
			else {
				if(!t1.second)t1=Get(l,l+j-1);
				else if(t1!=Get(l,l+j-1))ok=0;
				l+=j;
			}
		}
		if(ok&&t0!=t1)ans++;
	}
	cout<<ans;
}