#include <cstdio>
#include <cstring>
#define MAXN 3010

int n;
char str[MAXN];

int check(char c){
	if(c=='a') return 0;
	if(c=='e') return 0;
	if(c=='i') return 0;
	if(c=='o') return 0;
	if(c=='u') return 0;
	return 1;
}

void dp(){
	int cnt1=check(str[1]),cnt2=0;
	putchar(str[1]);
	for(int i=2;i<=n;i++){
		if(check(str[i])) cnt1++;
		else cnt1=0,cnt2=0;
		if(str[i]!=str[i-1] && check(str[i]) && check(str[i-1])) cnt2=1;
		if(cnt1>=3 && cnt2){
			putchar(' ');
			cnt1=check(str[i]);
			cnt2=0;
		}
		putchar(str[i]);
	}
}

int main(){
#ifdef DEBUG
	freopen("A.in","r",stdin);
#endif
	scanf("%s",str+1);
	n=strlen(str+1);
	dp();
}