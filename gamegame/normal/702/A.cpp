#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans=0,cnt=0;
	int a,prev=0;
	for(int i=1; i<=n ;i++){
		cin >> a;
		if(a>prev){
			cnt++;
			ans=max(ans,cnt);
		}
		else cnt=1;
		prev=a;
	}
	cout << ans << endl;
}