#include<bits/stdc++.h>
using namespace std;
int n,s[200005][26],q;
char a[200005];
bool Judge(int l,int r){
	if(l==r)return 0;
	int cnt=0;
	for(int j=0;j<26;j++)cnt+=(s[r][j]-s[l-1][j]>0);
	if(cnt>=3)return 0;
	if(cnt==1)return 1;
	if(cnt==2&&a[l]==a[r])return 1;
	return 0;
}
int main(){
	cin>>a+1,n=strlen(a+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)s[i][j]=s[i-1][j]+(a[i]==j+'a');
	}
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		puts(Judge(l,r)?"No":"Yes");
	}
}