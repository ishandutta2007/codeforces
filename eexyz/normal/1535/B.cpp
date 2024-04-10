#include<bits/stdc++.h>
using namespace std;
#define pf push_front
#define pb push_back
#define N 200005
#define ll long long
int i,j,k,n,T,x,y,v,a[N],ans;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i){
			for(j=1;j<i;++j){
				if(a[i]&a[j]&1)ans+=(gcd(a[i],a[j])!=1);
				else ++ans;
			}
		}
		cout<<ans<<"\n";
	}
}