#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
const int N=3e5+10;
char s[N];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	int l=0,r=n-1;
	while(l<=r){
		if(s[l]!=s[r]){
			printf("0\n");return 0;
		}
		int ct=0;
		while(l<=r&&s[l+1]==s[l])++l,++ct;
		if(l<=r)++l,++ct;
		while(l<=r&&s[r-1]==s[r])--r,++ct;
		if(l<=r)--r,++ct;
		if(l>r&&ct>=2){
			printf("%d\n",ct+1);return 0;
		}
		if(ct<3){
			printf("0\n");return 0;
		}
	}
	printf("0\n");
}