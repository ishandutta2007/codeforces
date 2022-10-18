#include <bits/stdc++.h>
char s[1000005];
int n,ans;
std::stack<int>stk;
int match(int i,int j){
	if (s[i]=='{'&&s[j]=='}')return 1;
	if (s[i]=='['&&s[j]==']')return 1;
	if (s[i]=='<'&&s[j]=='>')return 1;
	if (s[i]=='('&&s[j]==')')return 1;
	return 0;
}
int main(){
	scanf("%s",s+1);n=std::strlen(s+1);
	for(int i=1;i<=n;++i){
		if (s[i]=='{'||s[i]=='('||s[i]=='['||s[i]=='<')
			stk.push(i);
		else {
			if (stk.empty()){printf("Impossible");return 0;}
			int d=stk.top();stk.pop();
		//	printf("%c %c\n",s[i],s[d]);
			if (!match(d,i))ans++;
		}
	}if (!stk.empty()){printf("Impossible");return 0;}
	printf("%d",ans);return 0;
}