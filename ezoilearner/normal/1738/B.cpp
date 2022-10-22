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
int T,n,k,a[N],s[N];
inline void solve(){
	cin>>n>>k;
	For(i,n-k+1,n)cin>>s[i];
	For(i,n-k+2,n)a[i]=s[i]-s[i-1];
	if(k==1)return void(puts("YES"));
	if((ll)(n-k+1)*a[n-k+2]<s[n-k+1])
		return void(puts("NO"));
	For(i,n-k+2,n-1)
		if(a[i+1]<a[i])return void(puts("NO"));
	puts("YES");
}
int main(){
	cin>>T;
	while(T--)solve();
	return 0;
}