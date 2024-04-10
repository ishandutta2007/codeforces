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
string s;
int ln,li,le,lt;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='n')ln++;
        else if(s[i]=='i')li++;
        else if(s[i]=='e')le++;
        else if(s[i]=='t')lt++;
    }
    if(ln>3)ln+=(ln-3)/2;
    cout<<min(ln/3,min(li,min(le/3,lt)));
    return 0;
}