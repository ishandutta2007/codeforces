#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int n,k;
char str[101];

bool check(int l){
	for(int i=1;i<=l;++i)if(str[i]!=str[n-l+i])return false;
	return true;
}

int main(){
	scanf("%d%d%s",&n,&k,str+1);
	int l;for(l=n-1;l;--l)if(check(l))break;
	for(int i=1;i<=k;++i)for(int j=1;j<=n-l;++j)cout<<str[j];
	for(int i=n-l+1;i<=n;++i)cout<<str[i];
}