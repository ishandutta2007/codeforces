#include<bits/stdc++.h>
using namespace std;
int n,f[110];
char ch;
bool ans=false;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ch;f[ch-'a']++;
	}
	for (int i=0;i<26;i++) if (f[i]>=2) ans=true;
	if (n==1||ans) cout<<"Yes"<<endl;else cout<<"No"<<endl;
	return 0;
}