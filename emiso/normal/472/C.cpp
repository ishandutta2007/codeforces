#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<string,string> > names;

int main()
{
    int n,order;
    bool ok=true;
    string str1,str2,last;
    scanf("%d",&n);
    names.push_back(make_pair("aa","bb"));
    for(int i=1;i<=n;i++)
    {
            cin >> str1 >> str2;
            if (str1>str2) {
                 names.push_back(make_pair(str2,str1));
            }
            else {
                 names.push_back(make_pair(str1,str2));
            }
    }
    scanf("%d",&order);
    last = names[order].first;
    for(int i=2;i<=n;i++)
    {
            scanf("%d",&order);
            if(names[order].first > last) last = names[order].first;
            else {
                 if(names[order].second > last) last = names[order].second;
                 else ok=false;
            }
    }
    if(ok==true) printf("YES\n");
    else printf("NO\n");
    return 0;
}