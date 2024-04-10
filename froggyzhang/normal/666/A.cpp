#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;
#define N 100010
set<string> frogs;
inline int read(){
	int x=0,f=1;
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
string s,tmp; 
int dp[N][2];
int main(){
	cin>>s;
	int len=s.length();
	for(int i=len-1;i>=5;i--){
		if(i+2==len)dp[i][0]=1;
		if(i+3==len)dp[i][1]=1;
		if(i+2<len){
			if(dp[i+2][1])dp[i][0]=1;
			if(dp[i+2][0]&&(s[i+1]!=s[i+3]||s[i]!=s[i+2]))dp[i][0]=1;
		}
		if(i+3<len){
			if(dp[i+3][0])dp[i][1]=1;
			if(dp[i+3][1]&&(s[i+1]!=s[i+4]||s[i+2]!=s[i+5]||s[i]!=s[i+3]))dp[i][1]=1;
		}
	}
	for(int i=len-1;i>=5;i--){
		if(dp[i][0])frogs.insert(s.substr(i,2));
		if(dp[i][1])frogs.insert(s.substr(i,3));
	}
	cout<<frogs.size()<<endl;
	for(set<string>::iterator it=frogs.begin();it!=frogs.end();++it){
		cout<<(*it)<<endl;
	}
	return 0;
}