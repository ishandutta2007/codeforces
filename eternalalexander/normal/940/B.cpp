#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
ll n,k,a,b,x;
ll ans;
int main(){
	cin>>n>>k>>a>>b;x=n;
	if(k==1) {
		cout<<a*(n-1);
	}else {
		while(x!=1) {
			if(x%k==0) {
				ll d=x-x/k;
				if(d*a<=b) {
					ans+=a*(x-1);
					break;
				} else {
					x/=k;ans+=b;
				}
			}else {
				ans+=a*(x%k);
				x-=x%k;
			}
		}
		cout<<ans;
	}
    return 0;
}