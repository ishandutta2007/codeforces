#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int height[300005];
int cost[300005];
long long dp[300005][3];
inline void read(int& x) {
    x = 0;
    char ch = getchar();
    while (ch&16){ //this will break when \n or   is encountered
		x = (x << 3) + (x << 1) + (ch&15);
		ch = getchar();
	}
}
int main(){
    int TC;
    long long ans;
    read(TC);
    while (TC--){
        read(n);
        for (int x=1;x<=n;x++) read(height[x]),read(cost[x]);

        for (int x=0;x<=n;x++) dp[x][0]=dp[x][1]=dp[x][2]=1000000000000000000;
        dp[0][0]=0;

        for (int x=1;x<=n;x++){
            for (int y=0;y<3;y++){
                for (int z=0;z<3;z++){
                    if (height[x-1]+y!=height[x]+z) dp[x][z]=min(dp[x][z],dp[x-1][y]+z*cost[x]);
                }
            }
        }

        printf("%lld\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
    }
}