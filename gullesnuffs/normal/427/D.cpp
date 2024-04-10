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

char input[2][5005];
int best[2][5005], bestLen[2][5005];
int t[5005];
void KMPTable(char* W)
{
	int pos=2, cnd=0;
	t[0]=-1;
	t[1]=0;
	int wlen=strlen(W);
	while(pos <= wlen+1){
		if(W[pos-1] == W[cnd]){
			t[pos++]=++cnd;
		}
		else if(cnd > 0){
			cnd=t[cnd];
		}
		else{
			t[pos]=0;
			++pos;
		}
	}
}

pair<int, int> KMP(char* S, char* W, int skip){
	KMPTable(W);
	int m=0, i=0;
	int slen=strlen(S);
	int wlen=strlen(W);
	int best=-2, besti;
	bool unique=false;
	while(m < slen){
		if(m == skip){
			++m;
			i=0;
			continue;
		}
		if(i > best && i){
			best=i;
			besti=m;
			unique=1;
		}
		else if(i == best && i){
			unique=0;
		}
		if(W[i] == S[m+i] && W[i]){
			++i;
		}
		else{
			if(t[i] > -1){
				m += i-t[i];
				i=t[i];
			}
			else{
				i=0;
				m++;
			}
		}
	}
	/*if(i > best){
		best=i;
		besti=m;
		unique=1;
	}
	else if(i == best){
		unique=0;
	}*/
	/*if(!unique){
		return make_pair(-1, -1);
	}*/
	return make_pair(unique?besti:-1, best);
}


void calc(int i){
	for(int j=0; input[i][j]; ++j){
		//for(int k=0; input[!i][k]; ++k){
			pair<int, int> p=KMP(input[!i], input[i]+j, 999999);
			int maxLen=KMP(input[!i], input[i]+j, p.first).second;
			best[i][j]=p.first;
			if(p.second <= maxLen){
				if(p.first >= 0)
					printf("i=%d, j=%d, p.first=%d\n", i, j, p.first);
				assert(p.first < 0);
				best[i][j]=-1;
			}
			if(maxLen < 0)
				maxLen=0;
			bestLen[i][j]=maxLen+1;
		//}
	}
}

int main(){
	scanf("%s%s", input[0], input[1]);
	calc(0);
	calc(1);
	int ans=9999;
	for(int j=0; input[0][j]; ++j)
		for(int k=0; input[1][k]; ++k){
			if(best[0][j] == k && best[1][k] == j){
				ans=min(ans, max(bestLen[0][j], bestLen[1][k]));
			}
		}
	if(ans == 9999)
		ans=-1;
	printf("%d\n", ans);
	return 0;
}