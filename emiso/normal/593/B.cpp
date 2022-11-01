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
#define Y first.first
#define idx second
#define K first.second

using namespace std;
typedef long long ll;

vector<pair<pair<ll,ll> ,ll> > y_1,y_2;

bool compare1(pair<pair<ll,ll>,ll> a ,pair<pair<ll,ll>,ll> b ) {
    if(a.Y < b.Y) return true;
    if(a.Y == b.Y && a.K < b.K) return true;
    return false;
}

bool compare2(pair<pair<ll,ll>,ll> a ,pair<pair<ll,ll>,ll> b ) {
    if(a.Y < b.Y) return true;
    if(a.Y == b.Y && a.K > b.K) return true;
    return false;
}

int main()
{
    ll i,n,x_1,x_2,k,b;
    scanf("%I64d %I64d %I64d",&n,&x_1,&x_2);
    for(i=0;i<n;i++){
        scanf("%I64d %I64d",&k,&b);
        y_1.push_back(make_pair(make_pair(k*x_1 + b,k),i));
        y_2.push_back(make_pair(make_pair(k*x_2 + b,k),i));
    }
    sort(y_1.begin(),y_1.end(),compare1);
    sort(y_2.begin(),y_2.end(),compare2);
    int flag = 0;
    for(i=0;i<n;i++) {
        if(y_1[i].idx != y_2[i].idx) flag = 1;
    }
    if(flag == 0) printf("No\n");
    else printf("Yes\n");
    return 0;
}