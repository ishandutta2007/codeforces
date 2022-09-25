#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N],b[N];
char s[N];
void Read(int *a){
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
	}
}
int ODD(){
	int tmp=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(a[i]==b[i]){
			tmp+=a[i]?1:-1;
			++cnt;
		}
	}
	return tmp==1&&cnt&1?cnt:n+1;
}
int EVEN(){
	int tmp=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(a[i]^b[i]){
			tmp+=a[i]?1:-1;
			++cnt;
		}
	}
	return !tmp&&!(cnt&1)?cnt:n+1;
}
void Solve(){
	cin>>n;
	Read(a),Read(b);
	int ans=min(ODD(),EVEN());
	cout<<(ans>n?-1:ans)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}