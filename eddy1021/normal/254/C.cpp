#include <stdio.h>
#include <string.h>
#define C 100010
int cnt[30],cnt2[30],sum,tmp;
char s[C],t[C];
int main(){

	FILE *fin,*fout;
	fin = freopen("input.txt","r",stdin);
	fout = freopen("output.txt","w",stdout);

	scanf("%s%s",s,t);
	for( int i=0;s[i];i++ ) cnt[s[i]-'A']++,cnt2[t[i]-'A']++;
	for( int i=0;s[i];i++ )
		if( cnt[s[i]-'A']>cnt2[s[i]-'A'] ){
			tmp=s[i]-'A';
			for( int j=0;j<26;j++ )
				if( cnt[j]<cnt2[j] ){
					if( j<tmp || !cnt2[tmp] ){
						s[i]=j+'A'; cnt2[j]--; sum++;
					}else cnt2[tmp]--;
					break;
				}
			cnt[tmp]--;
		}
	printf("%d\n%s\n",sum,s);

	fclose(fin); fclose(fout);
}