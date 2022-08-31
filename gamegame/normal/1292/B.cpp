#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ax,bx,ay,by,x0,y0;
ll t;
int sz=0;
ll x[101],y[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	x[0]=x0;y[0]=y0;
	for(int i=1;  ;i++){
		x[i]=x[i-1]*ax+bx;
		y[i]=y[i-1]*ay+by;
		if((long double)1.0*x[i]*ax>=1e18){
			sz=i;break;
		}
		if((long double)1.0*y[i]*ay>=1e18){
			sz=i;break;
		}
	}
	ll xs,ys,t;cin >> xs >> ys >> t;
	int ans=0;
	for(int i=0; i<=sz ;i++){
		int cur=0;
		ll tc=t;
		ll xc=xs,yc=ys;
		for(int j=i; j>=0 ;j--){
			if(tc<abs(xc-x[j])+abs(yc-y[j])) break;
			tc-=abs(xc-x[j])+abs(yc-y[j]);
			xc=x[j];yc=y[j];
			cur++;
		}
		for(int j=i+1; j<=sz ;j++){
			if(tc<abs(xc-x[j])+abs(yc-y[j])) break;
			tc-=abs(xc-x[j])+abs(yc-y[j]);
			xc=x[j];yc=y[j];
			cur++;
		}
		ans=max(ans,cur);
	}
	cout << ans << '\n';
}