#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 23333
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
char s[N];
int T,n; 
void Solve(){
	scanf("%s",s+1);
	vector<int> vec;
	n=strlen(s+1);
	int p=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1')++p;
		if(p&&(i==n||s[i+1]=='0'))vec.push_back(p),p=0;
	} 
	sort(vec.begin(),vec.end(),greater<int>());
	int ans=0;
	for(int i=0;i<(int)vec.size();i+=2){
		ans+=vec[i];
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}