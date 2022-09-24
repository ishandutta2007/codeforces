#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
char s[200005];
void Solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	if(s[n]!='B')return puts("NO"),void();
	for(int i=1,x=0;i<=n;i++){
		if(s[i]=='A')x++;
		else x--;
		if(x<0)return puts("NO"),void();
	}
	puts("YES");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}