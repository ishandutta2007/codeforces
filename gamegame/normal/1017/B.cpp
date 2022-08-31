#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll cnt[4];
string s,t;
int main(){
	cin >> n >> s >> t;
	for(int i=0; i<n ;i++){
		cnt[(s[i]-48)*2+(t[i]-48)]++;
	}
	cout << cnt[0]*cnt[2]+cnt[0]*cnt[3]+cnt[1]*cnt[2] << endl;
}