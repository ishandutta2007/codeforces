#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		if((a+b)&1){
			puts("-1");
		}
		else if(!a&&!b){
			puts("0");
		}
		else if(a==b){
			puts("1");
		}
		else{
			puts("2");
		}
	}
	return 0;
}