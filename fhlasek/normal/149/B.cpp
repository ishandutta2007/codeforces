/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

char a[100],b[100];
int A,B;
vector<int> res;

int decode(char x){
	if(x>='0'&&x<='9') return x-'0';
	return x-'A'+10;
}

bool possible(int z){
	int sum = 0,tmp;
	REP(i,A){
		tmp = decode(a[i]);
		if(tmp >= z) return false;
		sum = sum * z + tmp;
		if(sum >= 24) return false;
	}
	sum = 0;
	REP(i,B){
		tmp = decode(b[i]);
		if(tmp >= z) return false;
		sum = sum * z + tmp;
		if(sum >= 60) return false;
	}
	return true;
}

char line[222];

int main(int argc, char *argv[]){
	scanf("%s",line);
	A = 0;
	B = 0;
	for(int i = 0; line[i]!=':'; i++) a[A++] = line[i];
	for(int i = A+1; line[i]!='\0'; i++) b[B++] = line[i];
	FOR(i,2,1000) if(possible(i)) res.push_back(i);
	if(!res.size()) printf("0\n");
	else{
		if(res.size() > 200) printf("-1\n");
		else{
			REP(i,(int)res.size()){
				if(i) printf(" ");
				printf("%d",res[i]);
			}
			printf("\n");
		}
	}
	return 0;
}