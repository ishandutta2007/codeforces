#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,A,B,C,a[N],b[N],c[N],an,bn,cn; // 1 , 0 ,bian
char s[N];
ll calc(int opt){
	static int _b[N],_c[N];
	for(int i=1;i<=bn;++i)_b[i]=0;
	for(int i=1;i<=cn;++i)_c[i]=0;
	int zz=0;
	for(int i=1;i<=an;++i)zz+=a[i]-1;
	ll ans=0,now=0;
	int j1=1,j2=1,k1=1,k2=1;
	while(j1<=bn&&b[j1]==1)++j1;
	while(k1<=cn&&c[k1]==1)++k1;
	if(!opt){
		if((j1>bn&&k1>cn)||!zz){
			if(j1<=bn||k1<=cn)ans=max(ans,now+A);
			if(j2==j1&&k2>cn)return ans;
			if(j2<j1){
				++j2,++zz;
			}
			else ++k2;
			now-=C;
		}
		else{
			if(j1<=bn){
				++_b[j1];
				now+=A;
				while(j1<=bn&&_b[j1]==b[j1]-1)++j1;
			}
			else{
				++_c[k1];
				now+=A;
				while(k1<=cn&&_c[k1]==c[k1]-1)++k1;
			}
		}
		ans=max(ans,now);
	}
	for(int i=1;i<=zz;++i){
		now+=B;
		ans=max(ans,now);
		if((j1>bn&&k1>cn)||i==zz){
			if(j1<=bn||k1<=cn)ans=max(ans,now+A);
			if(j2==j1&&k2>cn)break;
			if(j2<j1){
				++j2,++zz;
			}
			else ++k2;
			now-=C;
		}
		else{
			if(j1<=bn){
				++_b[j1];
				now+=A;
				while(j1<=bn&&_b[j1]==b[j1]-1)++j1;
			}
			else{
				++_c[k1];
				now+=A;
				while(k1<=cn&&_c[k1]==c[k1]-1)++k1;
			}
		}
		ans=max(ans,now);
	}
	return ans;
}
void Solve(){
	cin>>n>>A>>B>>C;
	cin>>(s+1);
	an=0,bn=0,cn=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&s[i]==s[j+1])++j;
		int len=j-i+1;
		if(s[i]=='0'){
			if(i==1||j==n)c[++cn]=len;
			else b[++bn]=len;
		}
		else{
			a[++an]=len;
		}
	}
	sort(b+1,b+bn+1);
	sort(c+1,c+cn+1);
	cout<<max(calc(0),calc(1))<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}