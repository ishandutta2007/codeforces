#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,f=0;
		cin>>n>>m;
		for(int i=1,a,b,c,d;i<=n;i++){
			cin>>a>>b>>c>>d;
			if(b==c)f=1;
		}
		if(f&&m%2==0)puts("YES");
		else puts("NO");
	}
}