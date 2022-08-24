#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
int a[25];
int b[73];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=72 ;i++){
		int num=i%12;
		if(num==2) b[i]=28+(i==38);
		else if(num==4 || num==6 || num==9 || num==11) b[i]=30;
		else b[i]=31;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=0; i<=72-n ;i++){
		bool ok=true;
		for(int j=1; j<=n ;j++){
			if(a[j]!=b[i+j]) ok=false;
		}
		if(ok){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}