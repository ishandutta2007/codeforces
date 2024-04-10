#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stack>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

vector<pair<int,int> > intervalo;
stack <int> open;
int dealt[100100];

int main()
{
    int ps,ss,ans = 0;
    string str,pat;

    cin >> str >> pat;
    ps = pat.size(), ss = str.size();

    for(int i=0;i<=ss-ps;i++) {
        if(str.substr(i,ps) == pat) {
            intervalo.push_back(make_pair(i,1));
            intervalo.push_back(make_pair(i+ps,0));
        }
    }

    sort(intervalo.begin(),intervalo.end());

    for(int i=0;i<intervalo.size();i++) {
        if(intervalo[i].second == 1) {
            open.push(intervalo[i].first);
        }
        else if(intervalo[i].second == 0 && dealt[intervalo[i].first-ps] == 0){
            if(!open.empty()) ans++;
            while(!open.empty()) {
                dealt[open.top()] = 1;
                open.pop();
            }
        }
        //printf("%d %d %d\n",intervalo[i].first,intervalo[i].second,dealt[i-ps]);
    }

    printf("%d\n",ans);

    return 0;
}
// |---|
//|--------|
//       |-------|
//            |-|