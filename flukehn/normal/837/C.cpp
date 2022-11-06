#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
int a,b,x[105],y[105],ans;
int main() {
	int n=read(),a=read(),b=read();
	for(int i=1; i<=n; i++) {
		x[i]=read(),y[i]=read();
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if((x[i]<=a&&x[j]<=a&&y[i]<=b&&y[j]<=b)&& (x[i]+x[j]<=a||y[i]+y[j]<=b)) {
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			} else if((x[i]<=a&&x[j]<=b&&y[i]<=b&&y[j]<=a)&& (x[i]+y[j]<=a||y[i]+x[j]<=b)) {
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			} else if((x[i]<=b&&x[j]<=a&&y[i]<=a&&y[j]<=b)&&(x[i]+y[j]<=b||y[i]+x[j]<=a) ) {
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			} else if((x[i]<=b&&x[j]<=b&&y[i]<=a&&y[j]<=a) &&(x[i]+x[j]<=b||y[i]+y[j]<=a)) {
				ans=max(ans,x[i]*y[i]+x[j]*y[j]);
			}
		}
	}
	cout<<ans<<endl;
}