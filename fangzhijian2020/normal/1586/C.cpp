#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,q,l,r,s[1000005];char c[1000005];
vector<char>v[1000005];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",c+1);
		for(int j=1;j<=m;++j){
			v[i].push_back(c[j]);
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			if(v[i][j]=='X'&&v[i+1][j-1]=='X')s[j+1]=1;
		}
	}
	for(int i=1;i<=m;++i)s[i]+=s[i-1];
	q=read();
	for(int i=1;i<=q;++i){
		l=read();r=read();
		if(l==r){
			puts("YES");
		}
		else{
			if(s[r]-s[l]){
				puts("NO");
			}
			else puts("YES");
		}
		
	}
	return 0;
}