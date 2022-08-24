#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
int a[51];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	string s;
	for(int i=1; i<k ;i++){
		a[i]=i;
	}
	for(int i=k; i<=n ;i++){
		cin >> s;
		if(s[0]=='N') a[i]=a[i-k+1];
		else a[i]=i;
	}
	for(int i=1; i<=n ;i++){
		if(a[i]>26){
			cout << (char)(a[i]+'A'-1-26) << (char)(a[i]+'a'-1-26);
		}
		else{
			cout << (char)(a[i]+'A'-1);
		}
		cout << ' ';
	}
	cout << '\n';
}