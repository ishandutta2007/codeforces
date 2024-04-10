#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int d,m,y;
    vector <int> v(3,0);
    scanf("%d.%d.%d\n",&d,&m,&y);
    scanf("%d.%d.%d\n",&v[0],&v[1],&v[2]);
    sort(v.begin(),v.end());
    bool ans=false;
    do{
        if (v[1]>12) continue;
        if (v[1]==1&&v[0]>31) continue;
        if (v[1]==2&&v[0]>29) continue;
        if (v[1]==3&&v[0]>31) continue;
        if (v[1]==4&&v[0]>30) continue;
        if (v[1]==5&&v[0]>31) continue;
        if (v[1]==6&&v[0]>30) continue;
        if (v[1]==7&&v[0]>31) continue;
        if (v[1]==8&&v[0]>31) continue;
        if (v[1]==9&&v[0]>30) continue;
        if (v[1]==10&&v[0]>31) continue;
        if (v[1]==11&&v[0]>30) continue;
        if (v[1]==12&&v[0]>31) continue;
        if (v[1]==2&&v[2]%4!=0&&v[0]>28) continue;
        if (v[0]==0||v[1]==0||v[2]==0) continue;
        if (y-v[2]<18) continue;
        if (y-v[2]>18) ans=true;
        if (m-v[1]>0) ans=true;
        if (m-v[1]<0) continue;
        if (d-v[0]>=0) ans=true;
    }while(next_permutation(v.begin(),v.end()));
    if (ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}