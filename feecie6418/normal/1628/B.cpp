#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,is[10][20005];
int id(string str){
	int t=0;
	for(char i:str)t=t*26+i-'a';
	return t;
}
void Solve(){
	memset(is,0,sizeof(is));
	scanf("%d",&n);
	bool F=0;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		string t;
		t=s;
		reverse(t.begin(),t.end());
		if(t==s)F=1;
		int len=s.length();
		if(is[len][id(t)])F=1;
		if(len==2&&is[6][id(t)])F=1;
		if(len==3&&is[5][id(t)])F=1;
		is[len][id(s)]=1;
		if(len==2){
			for(char j='a';j<='z';j++){
				string y=s;
				y+=j;
				is[5][id(y)]=1;
			}
		}
		if(len==3){
			string y="";
			y+=s[0],y+=s[1];
			is[6][id(y)]=1;
		}
	}
	if(F)cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}