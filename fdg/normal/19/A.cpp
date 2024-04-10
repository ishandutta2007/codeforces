#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

#define dat cin
#define sol cout
#define ll long long

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
//  ifstream dat("input.txt");
//  ofstream sol("output.txt");
    char names[51][51]={0};
    int n;
    scanf("%d\n",&n);
    vector <int> g(n,0),p(n,0),o(n,0);
    for(int i=0;i<n;i++)
        cin.getline(names[i],50,'\n');
    for(int i=0;i<n*(n-1)/2;i++)
    {
        char team1[51]={0},team2[51]={0},tmp[50]={0};
        int a,b;
        //scanf("%c-%c %d:%d\n",team1,team2,&a,&b);
        cin.getline(team1,50,'-');
        cin.getline(team2,50,' ');
        cin.getline(tmp,50,':');
        a=0;
        for(int j=0;j<strlen(tmp);j++)
        {
            a*=10;
            a+=tmp[j]-'0';
        }
        cin.getline(tmp,50,'\n');
        b=0;
        for(int j=0;j<strlen(tmp);j++)
        {
            b*=10;
            b+=tmp[j]-'0';
        }
        for(int j=0;j<n;j++)
        {
            if (strcmp(team1,names[j])==0)
            {
                g[j]+=a;
                p[j]+=b;
                if (a==b) o[j]+=1;
                if (a>b) o[j]+=3;
            }
            if (strcmp(team2,names[j])==0)
            {
                g[j]+=b;
                p[j]+=a;
                if (a==b) o[j]+=1;
                if (a<b) o[j]+=3;
            }
        }
    }
    bool used[51]={0};
    vector <string> ans;
    for(int i=0;i<n/2;i++)
    {
        int curt=-1;
        for(int j=0;j<n;j++)
        {
            if (used[j]) continue;
            if (curt==-1) curt=j;
            if (o[j]>o[curt]) curt=j;
            else
                if (o[j]==o[curt])
                    if (g[j]-p[j]>g[curt]-p[curt]) curt=j;
                    else
                        if (g[j]-p[j]==g[curt]-p[curt])
                            if (g[j]>g[curt]) curt=j;
        }
        ans.push_back(names[curt]);
        used[curt]=true;
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout << ans[i]<< endl;
    return 0;
}