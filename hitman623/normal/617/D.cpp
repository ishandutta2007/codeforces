#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x[3],y[3],i;
    for(i=0;i<3;++i)
        cin>>x[i]>>y[i];
    if(x[0]==x[1] && x[1]==x[2]) {cout<<1;exit(0);}
    if(y[0]==y[1] && y[1]==y[2]) {cout<<1;exit(0);}
    if(x[0]==x[1] && (y[2]<=y[1] && y[2]<=y[0] || y[2]>=y[1] && y[2]>=y[0])) {cout<<2;exit(0);}
    if(x[0]==x[2] && (y[1]<=y[2] && y[1]<=y[0] || y[1]>=y[2] && y[1]>=y[0])) {cout<<2;exit(0);}
    if(x[2]==x[1] && (y[0]<=y[1] && y[0]<=y[2] || y[0]>=y[1] && y[0]>=y[2])) {cout<<2;exit(0);}
    if(y[0]==y[1] && (x[2]<=x[1] && x[2]<=x[0] || x[2]>=x[1] && x[2]>=x[0])) {cout<<2;exit(0);}
    if(y[0]==y[2] && (x[1]<=x[2] && x[1]<=x[0] || x[1]>=x[2] && x[1]>=x[0])) {cout<<2;exit(0);}
    if(y[2]==y[1] && (x[0]<=x[1] && x[0]<=x[2] || x[0]>=x[1] && x[0]>=x[2])) {cout<<2;exit(0);}
    cout<<3;
    return 0;
}