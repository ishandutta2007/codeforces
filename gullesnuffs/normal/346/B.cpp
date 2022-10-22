#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

char s[2][105];
char virus[105];
/*int dp[105][105][105];
int prePos[105][105][105][3];*/
map<int, map<int, map<int, int> > > dp;
map<int, map<int, map<int, map<int, int> > > > prePos;

int main()
{
    scanf("%s%s%s", s[0], s[1], virus);
    for(int i=0; s[0][i]; ++i)
        for(int j=0; s[1][j]; ++j)
            for(int k=0; virus[k]; ++k)
                dp[i][j][k]=0;
    int ans[3]={0, 0, 0};
    for(int i=0; s[0][i]; ++i)
        for(int j=0; s[1][j]; ++j)
            for(int k=0; virus[k]; ++k){
                int pre;
                if(!i || !j){
                    pre=0;
                }
                else{
                    pre=dp[i-1][j-1][k];
                }
                if(i && dp[i-1][j][k] > dp[i][j][k] && prePos[i-1][j][k][1] < j){
                    dp[i][j][k]=dp[i-1][j][k];
                    prePos[i][j][k][0]=prePos[i-1][j][k][0];
                    prePos[i][j][k][1]=prePos[i-1][j][k][1];
                    prePos[i][j][k][2]=prePos[i-1][j][k][2];
                }
                if(j && dp[i][j-1][k] > dp[i][j][k] && prePos[i][j-1][k][0] < i){
                    dp[i][j][k]=dp[i][j-1][k];
                    prePos[i][j][k][0]=prePos[i][j-1][k][0];
                    prePos[i][j][k][1]=prePos[i][j-1][k][1];
                    prePos[i][j][k][2]=prePos[i][j-1][k][2];
                }
                if(s[0][i] == s[1][j]){
                    int kNew;
                    int iSaved=i, jSaved=j, kSaved=k;
                    for(kNew=k+1; kNew > 0; --kNew){
                        bool ok=1;
                        for(int m=0; m < kNew; ++m){
                            if(!m){
                                if(s[0][i] != virus[kNew-1]){
                                    ok=0;
                                    break;
                                }
                            }
                            else{
                                char c=s[0][prePos[i][j][k][0]+1];
                                int iTmp=prePos[i][j][k][0], jTmp=prePos[i][j][k][1], kTmp=prePos[i][j][k][2];
                                i=iTmp;
                                j=jTmp;
                                k=kTmp;
                                if(c != virus[kNew-m-1]){
                                    ok=0;
                                    break;
                                }
                            }
                        }
                        i=iSaved;
                        j=jSaved;
                        k=kSaved;
                        if(ok)
                            break;
                    }
                    if(virus[kNew] && dp[i][j][kNew] < pre+1){
                        dp[i][j][kNew]=pre+1;
                        prePos[i][j][kNew][0]=i-1;
                        prePos[i][j][kNew][1]=j-1;
                        prePos[i][j][kNew][2]=k;
                    }
                }
                if(dp[i][j][k] > dp[ans[0]][ans[1]][ans[2]]){
                    ans[0]=i;
                    ans[1]=j;
                    ans[2]=k;
                }
            }
    char ansS[105];
    if(!dp[ans[0]][ans[1]][ans[2]])
        printf("0\n");
    else{
        int i=ans[0], j=ans[1], k=ans[2];
        ansS[dp[i][j][k]]=0;
        while(i >= 0 && j >= 0 && dp[i][j][k]){
            if(prePos[i][j][k][0] < 0 || prePos[i][j][k][1] < 0 || dp[prePos[i][j][k][0]][prePos[i][j][k][1]][prePos[i][j][k][2]] < dp[i][j][k])
                ansS[dp[i][j][k]-1]=s[0][prePos[i][j][k][0]+1];
            int iTmp=prePos[i][j][k][0], jTmp=prePos[i][j][k][1], kTmp=prePos[i][j][k][2];
            i=iTmp;
            j=jTmp;
            k=kTmp;
        }
        printf("%s\n", ansS);
    }
    return 0;
}