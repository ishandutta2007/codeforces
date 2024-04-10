
 #pragma comment (linker, "/STACK:100000000")

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <string>
#define INF 1e9
#define LL long long
#define mp make_pair
#define pb push_back
#define ULL unsigned long long

using namespace std;
	


int main (){
	int n, m;
	cin >> n >> m;
    vector <vector <int> >  dp, g;
    g.assign (m, vector <int> (3, 0));
    dp.assign(n, vector <int> (2, 0));
	for (int i = 0; i < m; i++) {
      cin >> g[i][1]>> g[i][2]>> g[i][0];
    }
    sort(g.begin(), g.end());
    stack <int> chg;
    for (int i = 0; i < m ; i++){
if((i!=0 && g[i][0]>g[i-1][0]))
while(!chg.empty()){
int t = chg.top();
dp[t][0] = max(dp[t][1], dp[t][0]);
dp[t][1]=0;

chg.pop();
}
if (dp[g[i][1]-1][0] +1 > dp[g[i][2]-1][1]){
      dp[g[i][2]-1][1] = dp[g[i][1]-1][0] +1;
chg.push(g[i][2]-1);
}

    }
int ans =0;
for(int i=0;i<n;i++) ans =max(ans, max(dp[i][1],dp[i][0]));
cout<<ans;
}