#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin >> n;
	char a[n+1][4];
	bool ans=false;
	char crap;
	for(int i=1; i<=n ;i++){
		cin >> a[i][0] >> a[i][1] >> crap >> a[i][2] >> a[i][3];
		if(ans) continue;
		if(a[i][0]==a[i][1] && a[i][0]=='O'){
			ans=true;
			a[i][0]=a[i][1]='+';
			continue;
		}
		if(a[i][2]==a[i][3] && a[i][2]=='O'){
			ans=true;
			a[i][2]=a[i][3]='+';
		}
	}
	if(!ans){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i=1; i<=n ;i++){
		cout << a[i][0] << a[i][1] << crap << a[i][2] << a[i][3] << endl;
	}
}