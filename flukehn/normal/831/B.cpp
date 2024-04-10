#include<bits/stdc++.h>
using namespace std;
char s1[10000],s2[10000];
char t[1000];
int main(){
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=26;i++)if(s1[i]>'z'||s1[i]<'a')
		s1[i]=s1[i]-'A'+'a';
	for(int i=1;i<=26;i++)if(s2[i]>'z'||s2[i]<'a')
		s2[i]=s2[i]-'A'+'a';
	for(int i=1;i<=26;i++)	
		t[s1[i]]=s2[i];
	scanf("%s",s1+1);
	int n=strlen(s1+1);
	for(int i=1;i<=n;i++)if(s1[i]<='Z'&&s1[i]>='A')
		s1[i]=s1[i]-'A'+'a',s2[i]=t[s1[i]]-'a'+'A';
	else if(s1[i]<='z'&&s1[i]>='a')s2[i]=t[s1[i]];
	else s2[i]=s1[i];
	s2[n+1]='\0';
	puts(s2+1);
}