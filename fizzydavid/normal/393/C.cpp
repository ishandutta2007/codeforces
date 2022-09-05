#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
long long n;
int main()
{
    cin>>n;
    if(n==0)cout<<1;
    else if(n==1)cout<<4;
    else cout<<(int)(n*sqrt(2))*4;
    return 0;
}