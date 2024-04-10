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

char input[1000005];
long long dp[2][3];
//0=no more needed
//1=one more needed
//2=bomb

int main(){
	scanf("%s", input);
	bool read=0, write=1;
	dp[write][0]=1;
	dp[write][1]=1;
	dp[write][2]=0;
	for(int i=0; input[i]; ++i){
		read^=1;
		write^=1;
		for(int j=0; j < 3; ++j)
			dp[write][j]=0;
		int type=-1;
		if(input[i] == '0')
			type=0;
		else if(input[i] == '1')
			type=1;
		else if(input[i] == '2')
			type=2;
		else if(input[i] == '*')
			type=3;
		for(int j=0; j < 4; ++j){
			if(type != -1 && type != j)
				continue;
			for(int k=0; k < 3; ++k){
				if(!j && k == 2)
					continue;
				if(j == 3 && k == 0)
					continue;
				if(j != 3 && k == 1)
					continue;
				int left=j-(k==2);
				if(j == 3)
					dp[write][2] += dp[read][k];
				else if(left < 2)
					dp[write][left] += dp[read][k];
			}
		}
		for(int j=0; j < 3; ++j){
			dp[write][j] %= MOD;
			//printf("%I64d ", dp[write][j]);
		}
		//printf("\n");
	}
	long long ans=(dp[write][0]+dp[write][2])%MOD;
	printf("%I64d\n", ans);
	return 0;
}