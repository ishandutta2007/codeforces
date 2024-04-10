#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstring>

#define ll long long

using namespace std;

struct item{
    item(int a,int b,int c) : pow(a), dmg(b), num(c) {};
    int pow,dmg,num;
};

bool sort1(const item & a,const item & b)
{
    if (a.dmg>b.dmg||a.dmg==b.dmg&&a.pow<b.pow) return true;
    return false;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,Max,Reg,a,b,Val;
    cin >> n >> Max >> Reg;
    Val=Max;
    vector <item> v;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        v.push_back(item(a,b,i+1));
    }
    sort(v.begin(),v.end(),sort1);
    int s_dmg=0,time=0,last_max=Max;
    vector <int> sec,nums;
    while(true)
    {
        Max-=s_dmg;
        Max+=Reg;
        if (Max>Val) Max=Val;
        if (Max<=0)
        {
            printf("YES\n");
            printf("%d %d\n",time,nums.size());
            for(int i=0;i<nums.size();i++)
            {
                printf("%d %d\n",sec[i],nums[i]);
            }
            return 0;
        }
        sort(v.begin(),v.end(),sort1);
        bool fdg=false;
        for(int i=0;i<v.size();i++)
        {
            if (Max<=((double)Val*v[i].pow)/100)
            {
                s_dmg+=v[i].dmg;
                sec.push_back(time);
                nums.push_back(v[i].num);
                v.erase(v.begin()+i);
                fdg=true;
                break;
            }
        }
        time++;
        if (Max>=last_max&&fdg==false) break;
        last_max=Max;
    }
    printf("NO\n");
    return 0;
}