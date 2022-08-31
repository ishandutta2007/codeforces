#include<bits/stdc++.h>
using namespace std;

short dp[503][503] , tp[503][503];
int N , M , trs[503][2] , nxt[503]; char s1[503] , s2[503];

int main(){
	scanf("%d %d %s %s" , &N , &M , s1 + 1 , s2 + 1);
	nxt[0] = -1; trs[0][s2[1] - '0'] = 1;
	for(int i = 1 ; i <= M ; ++i){
		int p = nxt[i - 1]; while(p != -1 && s2[p + 1] != s2[i]) p = nxt[p];
		nxt[i] = p + 1;
		if(s2[i + 1] == '0') trs[i][0] = i + 1; else trs[i][0] = trs[nxt[i]][0];
		if(s2[i + 1] == '1') trs[i][1] = i + 1; else trs[i][1] = trs[nxt[i]][1];
	}
	memset(dp , 0x3f , sizeof(dp)); dp[0][0] = 0;
	for(int i = 1 ; i <= N ; ++i){
		memset(tp , 0x3f , sizeof(tp));
		for(int j = 0 ; j <= M ; ++j)
			for(int k = 0 ; k <= max(i - M , 0) ; ++k)
				if(dp[j][k] != 0x3f3f)
					for(int t = 0 ; t < 2 ; ++t){
						int r = trs[j][t] , nk = k + (r == M);
						tp[r][nk] = min(tp[r][nk] , (short)(dp[j][k] + (s1[i] - '0' != t)));
					}
		memcpy(dp , tp , sizeof(dp));
	}
	for(int i = 0 ; i <= N - M + 1 ; ++i){
		short mn = 0x3f3f;
		for(int j = 0 ; j <= M ; ++j)
			mn = min(mn , dp[j][i]);
		cout << (mn == 0x3f3f ? -1 : mn) << ' ';
	}
}