#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

bool rec(int n, int m, char* s, int pos){
	if(!n && !m){
		s[pos]=0;
		return true;
	}
	bool oneAllowed=1, zeroAllowed=1;
	if(pos && s[pos-1] == '0')
		zeroAllowed=0;
	if(pos > 1 && s[pos-1] == '1' && s[pos-2] == '1')
		oneAllowed=0;
	if(!n)
		zeroAllowed=0;
	if(!m)
		oneAllowed=0;
	if((m < n || !oneAllowed) && zeroAllowed){
		s[pos]='0';
		rec(n-1, m, s, pos+1);
	}
	else if(oneAllowed){
		s[pos]='1';
		rec(n, m-1, s, pos+1);
	}
	else
		return 0;
}

char ans[2000005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	bool res=rec(n, m, ans, 0);
	if(res)
		printf("%s\n", ans);
	else
		puts("-1");
	return 0;
}