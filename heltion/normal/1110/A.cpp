#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout<<"No";exit(0);};
auto read = [](){LL x;cin>>x;return x;}; 
#define maxn
int main(){
	ios::sync_with_stdio(false);
	
	LL b, k;
	cin >> b >> k;
	LL a, s = 0;
	for(int i = 0; i < k; i += 1){
		cin >> a;
		s = (s * b + a) % 2;
	}
	if(s % 2) cout << "odd";
	else cout << "even";
}