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
    int n,x[10]={0},y[10]={0},kol=0;
    cin >> n;
    string nums[10];
    for(int i=0;i<n;i++)
        cin >> nums[i] >> x[i] >> y[i];
    string res="";
    for(int i=100;i<10000;i++)
    {
        string cur="";
        int k=i;
        for(int j=0;j<4;j++)
        {
            cur+=k%10+'0';
            k/=10;
        }
        reverse(cur.begin(),cur.end());
        bool norm=true;
        for(int j=0;j<4;j++)
        {
            for(int t=j+1;t<4;t++)
                if (cur[j]==cur[t]) norm=false;
        }
        for(int j=0;j<n;j++)
        {
            int X=0,Y=0,dig[10]={0};
            for(int t=0;t<4;t++)
            {
                if (cur[t]==nums[j][t]) X++;
                else dig[cur[t]-'0']++;
            }
            for(int t=0;t<4;t++)
                if (cur[t]!=nums[j][t]&&dig[nums[j][t]-'0']>0)
                {
                    Y++;
                    dig[nums[j][t]-'0']--;
                }
            if (X!=x[j]||Y!=y[j]) norm=false;
        }
        if (norm) res=cur;
        kol+=norm;
    }
    if (kol==0) cout << "Incorrect data\n";
    if (kol==1) cout << res << endl;
    if (kol>1) cout << "Need more data\n";
    return 0;
}