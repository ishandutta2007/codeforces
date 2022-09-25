#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
int n;
char s[N],t[N];
vector<int> ans;
void Work(int x){
	ans.push_back(n-x);
	rotate(s+1,s+x+1,s+n+1);
	reverse(s+1,s+(n-x)+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>(s+1)>>(t+1);
	for(int i=1,l=(n+1)/2+1,r=(n+1)/2;i<=n;++i){
		char c;
		if(i&1)c=t[--l];
		else c=t[++r];
		int p=-1;
		for(int j=i;j<=n;++j){
			if(s[j]==c){
				p=j;break;
			}	
		}
		if(p==-1){
			cout<<-1<<'\n';
			return 0;
		}
		Work(p-1);
		Work(n-(p-i));
		if(!(n&1&&i==n))Work(n-i);
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	return 0;
}