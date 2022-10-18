#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <ctime>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int L,b,a,n;
    map <int,pair<int,int> > f;
//  f[L]=make_pair(1000,0);
    cin >> L >> b >> a >> n;
    for(int i=0;i<n;i++)
    {
        int T,S;
        cin >> T >> S;
        if (T==1)
        {
            if (f.size()==0)
            {
                if (L>=S)
                {
                    f[0]=make_pair(i+1,S);
                    cout << 0 << endl;
                }
                else cout << -1 << endl;
            }
            else
            {
                bool finded=false;
                if (f.size()==1)
                {
                    map <int,pair<int,int> >::iterator it=f.begin();
                    if (it->first>=S+a)
                    {
                        finded=true;
                        f[0]=make_pair(i+1,S);
                        cout << 0 << endl;
                    }
                    else
                    {
                        if (L-(it->first+it->second.second)>=S+b)
                        {
                            finded=true;
                            f[it->first+it->second.second+b]=make_pair(i+1,S);
                            cout << it->first+it->second.second+b << endl;
                        }
                    }
                }
                else
                {
                    map <int,pair<int,int> >::iterator it=f.begin(),prev=f.begin();
                    it++;
                    if (prev->first>=S+a)
                    {
                        f[0]=make_pair(i+1,S);
                        cout << 0 << endl;
                        continue;
                    }
                    for(;it!=f.end();it++,prev++)
                    {
                        if (it->first-(prev->first+prev->second.second)>=S+a+b)
                        {
                            f[prev->first+prev->second.second+b]=make_pair(i+1,S);
                            cout << prev->first+prev->second.second+b << endl;
                            finded=true;
                            break;
                        }
                    }
                    if (!finded)
                    {
                        it=f.end();
                        it--;
                        if (L-(it->first+it->second.second)>=S+b)
                        {
                            finded=true;
                            f[it->first+it->second.second+b]=make_pair(i+1,S);
                            cout << it->first+it->second.second+b << endl;
                        }
                    }
                }
                if (!finded)
                {
                    cout << -1 << endl;
                }
            }
        }
        else
        {
            for(map<int,pair<int,int> >::iterator it=f.begin();it!=f.end();it++)
            {
                if (it->second.first==S)
                {
                    f.erase(it);
                    break;
                }
            }
        }
    }
    return 0;
}