#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int a[100001];
int n,q;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=q ;i++){
		int x,y;cin >> x >> y;
		if(a[y]==3) cnt--;
		else if(a[y]!=0){
			if(y!=1 && a[y]+a[y-1]==3) cnt--;
			if(y!=n && a[y]+a[y+1]==3) cnt--;
		}
		a[y]^=1<<(x-1);
		if(a[y]==3) cnt++;
		else if(a[y]!=0){
			if(y!=1 && a[y]+a[y-1]==3) cnt++;
			if(y!=n && a[y]+a[y+1]==3) cnt++;
		}
		if(cnt==0) cout << "Yes\n";
		else cout << "No\n";
	}
}