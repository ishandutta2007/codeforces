#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int k, m;
    cin >> m >> k;
    map<int, set<int> > sm;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        sm[a].insert(b);
        sm[b].insert(a);
    }
    
    map<int, set<int> >::iterator it, it1;
    for(it = sm.begin(); it!= sm.end(); ++it)
    {
        int cn = 0;
        std::vector<int> rez;
        for(it1 = sm.begin(); it1!= sm.end(); ++it1)
            if((*it).first == (*it1).first)
                continue;
            else if((*it).second.find((*it1).first) != (*it).second.end())
                continue;
            else
            {
                std::vector<int> temp;
                set_intersection((*it).second.begin(), (*it).second.end(), (*it1).second.begin(), (*it1).second.end(), std::back_inserter(temp));
                if(temp.size() * 100 >= k * (*it).second.size())
                {
                    ++cn;
                    rez.push_back((*it1).first);
                }
            }
        cout << (*it).first <<": " << cn;
        for(int i = 0; i < cn; ++i)
            cout << " " << rez[i];
        cout << "\n";
    }   
            return 0;
}