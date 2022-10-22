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
#define MOD 1000000007
using namespace std;

int a[100005];
//int diff[150005][105];
int nCr[150005][105];
//int totDiff[150005][105];
int ansDiff[105];
vector<pair<int, pair<int, int> > > event;
/*int addDiff(int n, int k, int startK){
	if(n < 0){
		if(!first)diff[-n][k]=(diff[-n][k]-nCr[-n][k])%MOD;
		else totDiff[-n][k]=(diff[-n][k]-nCr[-n][k])%MOD;
	}
	else{
		if(!first)diff[n][k]=(diff[n][k]+nCr[n][k])%MOD;
		else totDiff[n][k]=(totDiff[n][k]+nCr[n][k])%MOD;
	}
	if(k)
		addDiff(n, k-1, startK);
}*/

int main(){
	for(int i=0; i < 150005; ++i)
		for(int j=0; j < 105; ++j){
			if(j > i)
				nCr[i][j]=0;
			else if(j == 0 || j == i)
				nCr[i][j]=1;
			else
				nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
		}
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	for(int i=0; i < m; ++i){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		event.push_back(make_pair(l, make_pair(k, k)));
		event.push_back(make_pair(r+1, make_pair(-(k+r-l+1), k)));
	}
	sort(event.begin(), event.end());
	/*for(int i=0; i < event.size(); ++i){
		pair<int, int> p =event[i];
		addDiff(p.first, p.second, p.second);
	}*/
	int ePos=0;
	for(int i=1; i <= n; ++i){
		while(ePos < event.size() && event[ePos].first == i){
			pair<int, int> p = event[ePos++].second;
			for(int j=0; j <= p.second; ++j){
				if(p.first < 0)
					ansDiff[j]=(ansDiff[j]-nCr[-p.first][p.second-j]+MOD)%MOD;
				else
					ansDiff[j]=(ansDiff[j]+nCr[p.first][p.second-j])%MOD;
			}
		}
		printf("%d ", (a[i-1]+ansDiff[0])%MOD);
		for(int j=0; j < 100; ++j)
			ansDiff[j]=(ansDiff[j]+ansDiff[j+1])%MOD;
	}
	return 0;
}