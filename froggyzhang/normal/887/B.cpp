#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
//???
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
int n,vis[3][10];
inline bool check(int x){
	static int p[10],f[5];
	int o=0;
	while(x)p[++o]=x%10,x/=10;
	if(o>n)return false;
	for(int i=0;i<n;++i)f[i]=i;
	do{
		bool ok=true;
		for(int i=1;i<=o;++i){
			if(!vis[f[i-1]][p[i]]){
				ok=false;break;
			}
		}
		if(ok)return true;
	}while(next_permutation(f,f+n));
	return false;
}
int main(){
	n=read();
	for(int i=0;i<n;++i){
		for(int j=0;j<6;++j){
			vis[i][read()]=1;
		}
	}
	for(int i=1;;++i){
		if(!check(i))return !printf("%d\n",i-1);
	}
	return 0;
}