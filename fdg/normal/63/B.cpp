#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,res=0;
    cin >> n >> k;
    vector <int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    while(true)
    {
        if (v.size()==0) break;
        vector <int> v1;
        bool used[101]={0},finded=false;
        for(int i=0;i<v.size();i++)
        {
            if (v[i]==k) continue;
            if (!used[v[i]])
            {
                finded=true;
                v1.push_back(v[i]+1);
                used[v[i]]=true;
            }
            else v1.push_back(v[i]);
        }
        if (!finded) break;
        res++;
        sort(v1.begin(),v1.end());
        v=v1;
    }
    cout << res << endl;
    return 0;
}