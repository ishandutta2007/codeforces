#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return 0;
} 
int n,a[MAXN],cnt,sum,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];}
	ans=a[1];
	for(int i=2;i<=n;i++) {
		if(a[1]>=a[i]*2){
			cnt++,ans+=a[i];
		}
	}
	if(ans*2>sum) {
		cout<<cnt+1<<'\n'<<1;
		for(int i=2;i<=n;i++) 
		    if(a[1]>=a[i]*2)cout<<' '<<i;
	}
	else cout<<0;
	return 0;
}