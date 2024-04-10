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

int times[205][4],ans;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    if(str[0] == 'U') times[0][0] =  1;

    else if(str[0] == 'D') times[0][1] =  1;

    else if(str[0] == 'L') times[0][2] =  1;

    else if(str[0] == 'R') times[0][3] =  1;

    for(int i=1;i<str.size();i++) {
        if(str[i] == 'U') times[i][0] = times[i-1][0] + 1;
        else times[i][0] = times[i-1][0];

        if(str[i] == 'D') times[i][1] = times[i-1][1] + 1;
        else times[i][1] = times[i-1][1];

        if(str[i] == 'L') times[i][2] = times[i-1][2] + 1;
        else  times[i][2] = times[i-1][2];

        if(str[i] == 'R') times[i][3] = times[i-1][3] + 1;
        else times[i][3] = times[i-1][3];
    }

    for(int i=0;i<str.size();i++) {
        if(times[i][0] == times[i][1] && times[i][2] == times[i][3]) ans++;
        for(int j = i+1; j<str.size(); j++) {
            if((times[j][0] - times[i][0]) == (times[j][1] - times[i][1])) {
                if((times[j][2] - times[i][2]) == (times[j][3] - times[i][3]))
                    ans++;
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}