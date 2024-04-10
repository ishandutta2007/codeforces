#include <bits/stdc++.h>

using namespace std;
char s[100005][10];
char* cur;

void setMin(char* st, bool nonzero){
	if(st[0] == 0)
		return;
	if(st[0] == '?'){
		if(nonzero)
			st[0]='1';
		else
			st[0]='0';
	}
	setMin(st+1, 0);
}

bool ok[10];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%s", s[i]);
	char start[10];
	start[0]='0';
	start[1]=0;
	cur=start;
	for(int i=0; i < n; ++i){
		if(strlen(s[i]) > strlen(cur))
			setMin(s[i], 1);
		else if(strlen(s[i]) < strlen(cur)){
			puts("NO");
			return 0;
		}
		else{
			ok[strlen(s[i])]=0;
			for(int j=strlen(s[i])-1; j >= 0; --j){
				if(s[i][j] == '?'){
					if(cur[j] < '9' || ok[j+1])
						ok[j]=1;
					else
						ok[j]=0;
				}
				else{
					if((s[i][j] == cur[j] && ok[j+1]) || s[i][j] > cur[j])
						ok[j]=1;
					else
						ok[j]=0;
				}
			}
			if(!ok[0]){
				puts("NO");
				return 0;
			}
			for(int j=0; j < strlen(s[i]); ++j){
				if((ok[j] && !ok[j+1]) || (s[i][j] != '?' && s[i][j] > cur[j])){
					if(s[i][j]=='?')s[i][j]=cur[j]+1;
					setMin(s[i]+j+1, 0);
					break;
				}
				else
					s[i][j]=cur[j];
			}
		}
		cur=s[i];
	}
	puts("YES");
	for(int i=0; i < n; ++i)
		printf("%s\n", s[i]);
}