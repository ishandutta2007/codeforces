#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <set>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

map <int,int> mapa;
set <int> rep;

int main()
{
    int i,n,m,flag=1,f[100100],b[100100];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&f[i]);
        if(mapa.find(f[i]) == mapa.end()) {
            mapa[f[i]] = i;
        }
        else {
            rep.insert(f[i]);
        }
    }
    for(int i=1;i<=m;i++) {
        scanf("%d",&b[i]);
        if(rep.find(b[i]) != rep.end() && flag == 1) flag = 0;
        else if(mapa.find(b[i]) == mapa.end()) flag = 2;
        else b[i] = mapa.find(b[i])->second;
    }
    if(flag == 0) printf("Ambiguity\n");
    else if(flag == 2) printf("Impossible\n");
    else {
            printf("Possible\n");
        for(int i=1;i<=m;i++) {
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    return 0;
}