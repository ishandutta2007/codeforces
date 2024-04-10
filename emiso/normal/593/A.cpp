#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int contains[110][26],sum[110],number[27][27];
string str[110],let[110];

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        cin >> str[i];
        for(int j=0;j<str[i].size();j++) {
            if(contains[i][str[i][j]-97] == 0) {
                contains[i][str[i][j]-97] = 1;
                let[i] += str[i][j];
            }
        }
        sort(let[i].begin(),let[i].end());

        if(let[i].size() > 2);
        else if(let[i].size() == 1) number[let[i][0]-96][0] += str[i].size();
        else number[let[i][0]-96][let[i][1]-96] += str[i].size();
    }
    int ma = 0;
    for(i=1;i<=26;i++) {
        for(int j=1;j<=26;j++) {
            if(i==j) continue;
            if(number[i][j] + number[i][0] + number[j][0] > ma) {
                ma = number[i][j] + number[i][0] + number[j][0];
            }
        }
    }
    printf("%d\n",ma);
    return 0;
}