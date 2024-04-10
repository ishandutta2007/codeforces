#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001],b[200001];
int p1=0;
bool in[200001];
bool easy(){
	if(p1==0) return false;
	for(int i=p1+1; i<=n ;i++){
		if(b[i]-b[i-1]!=1) return false;
	}
	for(int i=1; i<=n ;i++) in[a[i]]=true;
	for(int i=1; i<=p1-1 ;i++){
		if(!in[n-p1+i+1]) return false;
		in[b[i]]=true;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		if(b[i]==1) p1=i;
	}
	if(easy()){
		cout << p1-1 << endl;
		return 0;
	}
	int ma=0;
	for(int i=1; i<=n ;i++){
		if(b[i]!=0) ma=max(ma,i-b[i]+1);
	}
	cout << n+ma << endl;
}