#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
	char c[500005];
	scanf("%s",c);
	int l=1e9,r=0;
	int ok=0;
	for(int i=0;c[i]!=0;i++){
		if(c[i]=='[')ok=1;
		if(c[i]==':'&&ok){l=i;break;}
	}
	ok=0;
	for(int i=strlen(c)-1;i>=0;i--){
		if(c[i]==']')ok=1;
		if(c[i]==':'&&ok){r=i;break;}
	}
	int cnt=0;
	for(int j=l+1;j<r;j++){
		if(c[j]=='|')cnt++;
	}
	if(l>=r)printf("-1");
	else printf("%d\n",cnt+4);
}