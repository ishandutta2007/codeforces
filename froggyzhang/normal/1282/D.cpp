#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
string ans;
int Ask(const string &s){
	cout<<s<<endl;
	int x=read();
	if(!x)exit(0);
	return x;
}
int main(){
	int A=300-Ask(string(300,'a'));
	int B=300-Ask(string(300,'b'));
	n=A+B;
	int now=B;
	ans=string(n,'a');
	for(int i=0;i<n-1;++i){
		ans[i]='b';
		int tmp=Ask(ans);
		if(now<tmp){
			ans[i]='a';
		}
		now=min(now,tmp);
	}
	if(now)ans.back()='b';
	Ask(ans);
	return 0;
}