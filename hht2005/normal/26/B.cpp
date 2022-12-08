#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1),top=0,ans=0;
	for(int i=1;i<=n;i++) {
		if(s[i]=='(')top++;
		else {
			if(top)top--;
			else ans++;
		}
	}
	cout<<n-ans-top<<endl;
	return 0;
}