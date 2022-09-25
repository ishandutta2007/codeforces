#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,B,A,a[N],a1,b1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>A>>B;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	a1=A,b1=B;
	for(int i=1;i<=n;++i){
		if(!a1&&!b1){
			cout<<i-1<<'\n';
			return 0;
		}
		if(a[i]){
			if(a1&&b1<B)--a1,++b1;
			else --b1;
		}
		else{
			if(b1)--b1;
			else --a1;	
		}
	}
	cout<<n<<'\n';
	return 0;
}