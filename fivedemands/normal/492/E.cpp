#include<iostream>
using namespace std;
int a[1000000];
int main(){
	ios::sync_with_stdio(false);
	int m;
	long long dx,dy,n,p,q;
	cin >> n >> m >> dx >> dy;
	int ans1,ans2,maxi=0;
	for(int i=1; i<=m ;i++){
		cin >> p >> q;
		int num=((p*dy-q*dx)%n+n)%n;
		a[num]++;
		if(a[num]>maxi){
			maxi=a[num];
			ans1=p,ans2=q;
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
}