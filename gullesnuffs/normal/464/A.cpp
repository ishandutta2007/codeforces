#include <bits/stdc++.h>

using namespace std;

char inp[1005];
int n, p;


bool rec(int pos){
	if(pos == n)
		return true;
	for(; inp[pos]-'a' < p; ++inp[pos]){
		if(pos && inp[pos-1] == inp[pos])
			continue;
		if(pos > 1 && inp[pos-2] == inp[pos])
			continue;
		if(rec(pos+1))
			return 1;
	}
	inp[pos]='a';
	return 0;
}

int main(){
	scanf("%d%d", &n, &p);
	scanf("%s", inp);
	++inp[strlen(inp)-1];
	if(rec(0))
		printf("%s\n", inp);
	else
		puts("NO");
}