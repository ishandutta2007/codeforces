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
float n;
int main()
{
    cin>>n;
    for(float a=1;a<=10;a++)
    {
        for(float h=1;h<=10;h++)
        {
            if(abs(a*h/2/sqrt(a*a/4+h*h)-n)<=0.0001){cout<<a<<" "<<h;return 0;}
        }
    }
    return 0;
}