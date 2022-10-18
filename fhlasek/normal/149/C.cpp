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

vector<pair<int,int> > v;
int N;

vector<int> a,b;

int main(int argc, char *argv[]){
	int s;
	scanf("%d",&N);
	REP(i,N){
		scanf("%d",&s);
		v.push_back(make_pair(s,i+1));
	}
	sort(v.begin(),v.end(),greater<pair<int,int> > ());
	REP(i,N){
		if(i%4 == 0 || i%4 == 3) a.push_back(v[i].second);
		else b.push_back(v[i].second);
	}
	printf("%d\n",(int)a.size());
	REP(i,(int)a.size()){
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",(int)b.size());
	REP(i,(int)b.size()){
		if(i) printf(" ");
		printf("%d",b[i]);
	}
	return 0;
}