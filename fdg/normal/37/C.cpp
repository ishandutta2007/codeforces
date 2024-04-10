#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <string>

#define ll long long

using namespace std;

string add(string str)
{
    reverse(str.begin(),str.end());
    int r=0,p=1;
    for(int i=0;i<str.size();i++)
    {
        r=p+str[i]-'0';
        str[i]=r%2+'0';
        p=r/2;
    }
    if (p>0) str.push_back('1');
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a;
    scanf("%d",&n);
    vector <int> v,r;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        r.push_back(a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    /*int step2=2;
    for(int i=1;i<=10;i++)
    {
        if (v[i]>=step2)
        {
            printf("NO\n");
            return 0;
        }
        step2*=2;
    }*/
    string pref="0";
    vector <string> ans;
    for(int i=0;i<v.size();i++)
    {
        while(pref.size()<v[i]) pref.push_back('0');
        if (pref.size()>v[i])
        {
            printf("NO\n");
            return 0;
        }
        ans.push_back(pref);
        bool zero=false;
        for(int i=0;i<pref.size();i++)
            if (pref[i]=='0')
            {
                zero=true;
                break;
            }
        if (zero==false&&i+1!=v.size())
        {
            printf("NO\n");
            return 0;
        }
        pref=add(pref);
    }
/*  vector <string> ans,nums;
    vector <string> prefix;
    int cur=0;
    for(int i=0;i<=1000;i++)
    {
        char mas[100]={0};
        ltoa(i,mas,2);
        nums.push_back(mas);
    }
    for(int i=1;i<=1000;i++)
    {
        int f=0;
        for(int j=0;j<v[i];j++,f++)
        {
            string zero="";
            if (i<pref.size()+nums[f].size())
            {
                f=0;
                bool finded=false;
                while (cur<prefix.size())
                {
                    if (prefix[cur].size()+nums[f].size()<=i)
                    {
                        finded=true;
                        pref=prefix[cur];
                        cur++;
                        break;
                    }
                    cur++;
                }
                if (i<pref.size()+nums[f].size()||finded==false)
                {
                    printf("NO\n");
                    return 0;
                }
            }
            if (i>pref.size()+nums[f].size())
            {
                zero.resize(i-pref.size()-nums[f].size(),'0');
            }
            ans.push_back(pref+zero+nums[f]);
        }
        if (v[i]>0)
        {
            for(int j=f+1;j<=1000;j++)
            {
                if (pref.size()+nums[j].size()<=i)
                    prefix.push_back(pref+nums[j]);
                else break;
            }
            pref+=nums[f];
        }
        
    }*/
    if (ans.size()!=r.size())
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    bool used[2002]={0};
    for(int i=0;i<r.size();i++)
    {
        for(int j=0;j<ans.size();j++)
            if (ans[j].size()==r[i]&&used[j]==false)
            {
                cout << ans[j] << endl;
                used[j]=true;
               break; 
            }
    }
//  for(int i=0;i<ans.size();i++)
//      cout << ans[i] << endl;
    return 0;
}