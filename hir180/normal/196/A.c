#include <stdio.h>
#include <string.h>
char s[100005];int cnt[26],n,i,cur=0,tot=0;
char t[100005];
int main(){
	scanf("%s",s); n=strlen(s);
	for(i=0;i<n;i++) cnt[s[i]-'a']++;
	for(i=25;i>=0;i--){
		while(cnt[i]){
			while(s[cur]!='a'+i) cnt[s[cur]-'a']--,cur++;
			t[tot++]='a'+i; cnt[s[cur]-'a']--; cur++;
		}
	}
	for(i=0;i<tot;i++) printf("%c",t[i]);
}