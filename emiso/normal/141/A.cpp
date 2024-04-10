#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    string s1,s2,s3;
    int ok=1,pos;
    cin >> s1 >> s2 >> s3;
    
    sort(s1.begin(),s1.end());
    sort(s3.begin(),s3.end());
    sort(s2.begin(),s2.end());
    
    for(int i=0;i<s1.size();i++)
    {
            pos = s3.find(s1[i]);
            if(pos == -1)
            {
                   ok=0;
                   break;
            }
            
            else s3.erase(pos,1);
    }
    if(ok ==1) for(int i=0;i<s2.size();i++)
    {
            pos = s3.find(s2[i]);
            if(pos == -1)
            {
                   ok=0;
                   break;
            }
            else s3.erase(pos,1);
    }
    if(!s3.empty()) ok=0;
    if(ok==0) puts("NO");
    else puts("YES");
    return 0;
}