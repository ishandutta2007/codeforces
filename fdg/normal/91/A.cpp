#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

int pos[10004][27]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    string s1,s2;
    cin >> s1 >> s2;
    for(int i=0;i<26;i++)
        pos[s1.size()-1][i]=-1;
    pos[s1.size()-1][s1[s1.size()-1]-'a']=s1.size()-1;
    for(int i=s1.size()-2;i>=0;i--)
    {
        for(int j=0;j<26;j++) pos[i][j]=pos[i+1][j];
        pos[i][s1[i]-'a']=i;
    }
    int cnt=0,p=0;
    while(true)
    {
        if (p==s2.size()) break;
        cnt++;
        bool finded=false;
        for(int i=0;p<s2.size()&&i<s1.size();i++)
        {
            if (pos[i][s2[p]-'a']!=-1)
            {
                i=pos[i][s2[p]-'a'];
                p++;
                finded=true;
            } else break;
        }
        if (!finded)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}