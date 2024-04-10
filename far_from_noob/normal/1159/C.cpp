#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin >>n>>m;
    long long  b[n],g[m];
    for(int i=0;i<n;i++){
        cin >>b[i];
    }
    for(int i=0;i<m;i++){
        cin >>g[i];
    }
    sort(b,b+n);
    sort(g,g+m);

    long long countans=0;
    for(int i=0;i<n-1;i++){
        countans+= b[i]*m;
    }
    for(int i=1;i<m;i++){
        countans+=g[i];
    }
    if(b[n-1]==g[0])cout<< countans+b[n-1];
    else if(b[n-1]>g[0])cout<<-1;
    else {
        countans+=g[0]-b[n-2]+b[n-1];
        cout<< countans;
    }
    return 0;
}