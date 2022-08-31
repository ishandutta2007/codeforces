#include<iostream>
using namespace std;
int n;
int minx=2e8,maxx=-2e8,miny=2e8,maxy=-2e8;
int x[300001],y[300001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
		minx=min(x[i],minx);
		maxx=max(x[i],maxx);
		miny=min(y[i],miny);
		maxy=max(y[i],maxy);
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		ans=max(ans,abs(x[i]-minx)+abs(y[i]-miny));
		ans=max(ans,abs(x[i]-minx)+abs(y[i]-maxy));
		ans=max(ans,abs(x[i]-maxx)+abs(y[i]-miny));
		ans=max(ans,abs(x[i]-maxx)+abs(y[i]-maxy));
	}
	cout << ans*2;
	for(int i=4; i<=n ;i++){
		cout << ' ' << (maxx-minx+maxy-miny)*2;
	}
}