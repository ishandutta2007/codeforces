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

#define MAX_NEEDLE 1111
int N; //lenght of the needle
char needle[MAX_NEEDLE];
int fail[MAX_NEEDLE];

void failure(){ //precomputes the failure function
  int k;
  fail[0] = -1;
  FOR(i,1,N){
    for(k=fail[i-1]; k>=0 && needle[k] != needle[i-1]; k=fail[k]) ;
    fail[i] = k+1;
  }
}

#define MAX_TEXT 111111
int T; //lenght of the text
char text[MAX_TEXT];

int best1[MAX_TEXT], best2[MAX_TEXT];

void kmp()
{
    int i=0, j=0;
  	REP(x,T+1) best1[x] = 0;
    while (i<T)
    {
        while (j>=0 && text[i] != needle[j]) j=fail[j];
        i++; j++;
    	best1[i] = max(max(best1[i-1],best1[i]),j);
        if (j==N) j=fail[j];
    }
}

void kmp2()
{
    int i=0, j=0;
  	REP(x,T+1) best1[x] = 0;
    while (i<T)
    {
        while (j>=0 && text[T-i-1] != needle[j]) j=fail[j];
        i++; j++;
    	best1[i] = max(max(best1[i-1],best1[i]),j);
        if (j==N) j=fail[j];
    }
}

bool possible(){
	if(N<2) return false;
	failure();
	kmp();
	REP(i,T+1) best2[i] = best1[i];
	reverse(needle,needle+N);
	failure();
	kmp2();
	FOR(i,1,T-1) if(best2[i] + best1[T-i] >= N) return true;
	return false;
}

int main(int argc, char *argv[]){
	scanf("%s",text);
	T = strlen(text);
	int Q,res = 0;
	scanf("%d",&Q);
	while(Q--){
		scanf("%s",needle);
		N = strlen(needle);
		if(possible()) res++;
	}
	printf("%d\n",res);
	return 0;
}