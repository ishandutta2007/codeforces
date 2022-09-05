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
#include<ctime>
#include<utility>
#include<vector>
using namespace std; 
int a,b,c,d,e;
int main()
{
    cin>>a>>b>>c>>d>>e;
    cout<<min(a,min(b,min(c/2,min(d/7,e/4))));
    return 0;
}