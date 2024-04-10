#include<iostream>
using namespace std;
int n;
int h[100001];
int fr[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	h[1]=1;
	fr[1]=1;
	for(int i=2; i<=n ;i++){
		int p;
		cin >> p;
		h[i]=h[p]+1;
		fr[h[i]]^=1;
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		ans+=fr[i];
	}
	cout << ans << endl;
}