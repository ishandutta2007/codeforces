#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char mas[120]={0};
    map <string, set <string> > f1,f2;
    while(gets(mas))
    {
        int l=strlen(mas);
//      mas[l]='.';
        string s=mas;
        l=s.find("\\",0);
        while(true)
        {
            l=s.find("\\",l+1);
            if (l==-1) break;
            int ni=l;
            while(true)
            {
                ni=s.find("\\",ni+1);
                if (ni==-1) break;
                f1[s.substr(0,l)].insert(s.substr(0,ni));
            }
            f2[s.substr(0,l)].insert(s);
        }
    }
    int a1=0,a2=0;
    for(map <string, set <string> >::iterator it=f1.begin();it!=f1.end();it++)
        if ((*it).second.size()>a1) a1=(*it).second.size();
    for(map <string, set <string> >::iterator it=f2.begin();it!=f2.end();it++)
        if ((*it).second.size()>a2) a2=(*it).second.size();
    cout << a1 << " " << a2 << endl;
    return 0;
}