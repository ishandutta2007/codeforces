#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map<string,int> poll;

struct OUT
{
    string s;
    int w;
    bool operator < (const OUT &p) const
    {
        if (w != p.w) return w > p.w;
        return s < p.s;
    }
} ou[1024];

int main()
{

    string nam,name;
    int n;
    cin >> nam >> n;
    string name1,opt;
    poll.clear();
    for (int i = 0;i < n;++i)
    {
        cin >> name >> opt;
      //  cout << name << opt;
        if ("posted" == opt)
        {
       //     cout << 1;

            cin >> opt >> name1 >> opt;
            name1 = string(name1,0,name1.size()-2);
            if (name1 != nam && name != nam)
            {
                if (poll.find(name1) == poll.end())
                    poll[name1] = 0;
                if (poll.find(name) == poll.end())
                    poll[name] = 0;
                continue;
            }
            if (name1 == nam && name == nam)
                continue;
            if (name1 == nam) name1 = name;
            if (name1 != nam)
            {
                if (poll.find(name1) != poll.end())
                    poll[name1] += 15;
                else
                    poll[name1] = 15;
            }
        }
        else
        if ("commented" == opt)
        {
    //        cout << 2;
            cin >> opt >> name1 >> opt;
            name1 = string(name1,0,name1.size()-2);
            if (name1 != nam && name != nam)
            {
                if (poll.find(name1) == poll.end())
                    poll[name1] = 0;
                if (poll.find(name) == poll.end())
                    poll[name] = 0;
                continue;
            }
            if (name1 == nam && name == nam)
                continue;
            if (name1 == nam) name1 = name;
            if (name1 != nam)
            {
                if (poll.find(name1) != poll.end())
                    poll[name1] += 10;
                else
                    poll[name1] = 10;
            }
        }
        else
        {
   //         cout << 3;
            cin >> name1 >> opt;
            name1 = string(name1,0,name1.size()-2);
            if (name1 != nam && name != nam)
            {
                if (poll.find(name1) == poll.end())
                    poll[name1] = 0;
                if (poll.find(name) == poll.end())
                    poll[name] = 0;
                continue;
            }
            if (name1 == nam && name == nam)
                continue;
            if (name1 == nam) name1 = name;
            if (name1 != nam)
            {
                if (poll.find(name1) != poll.end())
                    poll[name1] +=5;
                else
                    poll[name1] = 5;
            }
        }
    }
        int ret = 0;
        for (map<string,int>::iterator i = poll.begin();i != poll.end();++i)
        {
            ou[ret].s = i->first;
            ou[ret++].w = i->second;
        }
        sort(ou,ou+ret);
        for (int i = 0;i < ret;++i)
            cout << ou[i].s << endl;
    return 0;
}