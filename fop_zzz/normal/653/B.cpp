#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
#include <complex>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x){
	write(x);puts("");
}
int n,q,ans=0;
vector<string>e[10];
map<string,bool>mp;
inline string cop(string s,int q,int l){
	if(q>=l)return "";
	string p="";
	for(int i=q;i<l;i++)p=p+s[i];
	return p;
}
inline void dfs(string s){
	if(mp[s])return;mp[s]=1;
	if(s.size()==n){ans++;return;}
	for(int i=0;i<1;i++){
		for(int j=0;j<e[s[i]-'a'].size();j++){
			string t=e[s[i]-'a'][j];
			dfs(cop(s,0,i)+t+cop(s,i+1,s.size()));
		}
	}
}
int main()
{
	n=read();q=read();
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		int p=t[0]-'a';e[p].push_back(s);
	}
	dfs("a");writeln(ans);
	return 0;
}