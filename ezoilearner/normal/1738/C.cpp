#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e5+5;
int T,n,a[N];
inline void solve(){
	cin>>n;
	int odd=0,even;
	For(i,1,n)cin>>a[i],odd+=(a[i]&1);
	even=n-odd;
	if(odd%4==2)puts("Bob");
	else if(odd%4==3)puts("Alice");
	else if(odd%4==0)puts("Alice");
	else if(even&1)puts("Alice");
	else puts("Bob");
}
int main(){
	cin>>T;
	while(T--)solve();
	return 0;
}