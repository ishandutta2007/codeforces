#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char str[1005]; 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>str+1;
		if(n%2){
		int o=0;
		for(int i=1;i<=n;i+=2)if(str[i]%2)o++;
		if(o)puts("1");
		else puts("2");
		}
		else {
			int o=0;
		for(int i=2;i<=n;i+=2)if(str[i]%2==0)o++;
		if(o)puts("2");
		else puts("1");
		}
	}
}