#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int sm=t.length()<=s.length();
    size_t p=0;
    if(sm)
        for(size_t i=0; i<t.size(); i++)
        {
            while(p<s.length() && s[p]!=t[i])
                p++;
            if(p==s.length())
            {
                sm=0;
                break;
            }
            p++;
        }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int sa=s==t;
    multiset<char> ms;
    for(auto it: s)
        ms.insert(it);
    int sam=1;
    for(auto it: t)
    {
        if(!ms.count(it))
        {
            sam=0;
            break;
        }
        ms.erase(ms.find(it));
    }
    if(sa)
        printf("array\n");
    else if(sm)
        printf("automaton\n");
    else if(sam)
        printf("both\n");
    else
        printf("need tree\n");
}