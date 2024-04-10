#include<bits/stdc++.h>
using namespace std;
//y*(i-p)+b_i*x
int n,p,k;
#define Maxn 100010
int b[Maxn];
char a[Maxn];

int main(){
	int T;cin>>T;
	while(T--){
		cin>>n>>p>>k; 
		scanf("%s",a+1);
		int x,y;cin>>x>>y;
		int ans=(1ll<<31)-1;
		for(int i=n;i>=1;--i){
			b[i]=1-(a[i]-'0');
			if(i+k<=n)b[i]+=b[i+k];
			if(i>=p)ans=min(ans,y*(i-p)+b[i]*x);
		}
		cout<<ans<<endl;
	}
}