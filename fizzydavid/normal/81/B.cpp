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
#define ff first
#define ss second
string s1,s2;
int s2i;
int main()
{
    getline(cin,s1);
    int b;
    if(s1[0]=='.')b=3,s2[0]=s1[0],s2[1]=s1[1],s2[2]=s1[2],s2i=2;else b=1,s2[0]=s1[0],s2i=0;
    if(s1[0]==','&&s1.size()>1)s2i++,s2[s2i]=' ';
    for(int i=b;i<s1.size();i++)
    {
        if(s1[i]=='.')
        {
            if(s2[s2i]!=' ')s2[s2i+1]=' ',s2i++;
            s2[s2i+1]='.';s2[s2i+2]='.';s2[s2i+3]='.';
            s2i+=3;i+=2;
        }
        else if(s1[i]==',')
        {
            s2[s2i+1]=',';if(i<s1.size()-1)s2[s2i+2]=' ',s2i++;
            s2i++;
        }
        else if(s1[i]>='0'&&s1[i]<='9')
        {
            if(s2[s2i]>='0'&&s2[s2i]<='9'&&s1[i-1]==' ')s2i++,s2[s2i]=' ';
            s2[s2i+1]=s1[i];
            s2i++;
        }
    }
    for(int i=0;i<=s2i;i++)cout<<s2[i];
//  system("pause");
    return 0;
}