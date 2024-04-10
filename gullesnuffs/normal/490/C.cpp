#include <bits/stdc++.h>

using namespace std;

char s[1000005];
long long a, b;
long long mod[1000005];

int main(){
	scanf("%s", s);
	scanf("%I64d%I64d", &a, &b);
	int n=strlen(s);
	mod[n]=0;
	int ten=1;
	for(int i=n-1; i >= 0; --i){
		mod[i]=(mod[i+1]+ten*(s[i]-'0'))%b;
		ten=(ten*10)%b;
	}
	int sum=0;
	for(int i=0; i < n-1; ++i){
		sum=(sum*10+s[i]-'0')%a;
		if(s[i+1] == '0')
			continue;
		if(sum)
			continue;
		if(mod[i+1])
			continue;
		puts("YES");
		char c=s[i+1];
		s[i+1]=0;
		printf("%s\n", s);
		s[i+1]=c;
		printf("%s\n", s+i+1);
		return 0;
	}
	puts("NO");
}