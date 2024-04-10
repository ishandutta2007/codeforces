#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

char s[105], t[105];
int ns[128], nt[128];

int main(){
	scanf("%s", s);
	scanf("%s", t);
	for(int i=0; s[i]; ++i)
		ns[s[i]]++;
	for(int i=0; t[i]; ++i)
		nt[t[i]]++;
	int best=0;
	for(int i=0; s[i]; ++i){
		if(s[i]== t[best])
			++best;
	}
	if(!t[best]){
		puts("automaton");
	}
	else{
		bool ok=1;
		for(int i=0; i < 128; ++i)
			if(nt[i] > ns[i])
				ok=0;
		if(ok && strlen(s) == strlen(t))
			puts("array");
		else if(ok)
			puts("both");
		else
			puts("need tree");
	}
	return 0;
}