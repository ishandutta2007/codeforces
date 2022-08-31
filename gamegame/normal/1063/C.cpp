#include<iostream>
using namespace std;
typedef long long ll;
ll prvb=500,prvw=(1<<30)+500;
int n;
void putpos(ll num){
	cout << num/2+num%2 << ' ' << num/2 << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int mid=(prvb+prvw)/2;
		putpos(mid);
		string s;
		cin >> s;
		if(s=="black") prvb=mid;
		else prvw=mid;
	}
	if(prvb%2==0){
		cout << prvb/2 << ' ' << prvb/2+1 << ' ' << prvb/2+1 << ' ' << prvb/2-1 << endl;
	}
	else{
		cout << prvb/2 << ' ' << prvb/2+1 << ' ' << prvb/2+2 << ' ' << prvb/2 << endl;
	}
}