#include<bits/stdc++.h>
using namespace std;
char s[100010],t[100010],S[26];
int n,k,c[26],cnt;
int main() {
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)c[s[i]-'a']=1;
	for(int i=0;i<26;i++)
		if(c[i])S[cnt++]=i+'a';
	if(n<k) {
		cout<<s+1;
		for(int i=n+1;i<=k;i++)cout<<S[0];
		cout<<endl;
	} else {
		int i;
		for(i=k;i>=1;i--)
			if(s[i]!=S[cnt-1])break;
			else t[i]=S[0];
		for(int j=0;j<cnt;j++)
			if(S[j]>s[i]) {
				t[i]=S[j];
				break;
			}
		for(i=i-1;i>=1;i--)t[i]=s[i];
		cout<<t+1<<endl;
	}
	return 0;
}