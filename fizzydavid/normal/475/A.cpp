//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
char s[6][28]={{"+------------------------+ "},
                     {"|#.#.#.#.#.#.#.#.#.#.#.|D|)"},
                     {"|#.#.#.#.#.#.#.#.#.#.#.|.| "},
                     {"|#.......................| "},
                     {"|#.#.#.#.#.#.#.#.#.#.#.|.|)"},
                     {"+------------------------+ "}};
int main()
{
    ios::sync_with_stdio(false);
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<27;i++)
    {
        for(int j=1;j<5;j++)
        {
            if(s[j][i]=='#')
            {
                s[j][i]='O';
                cnt++;
            }
            if(cnt==n)break;
        }
        if(cnt==n)break;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<27;j++)
        {
            if(s[i][j]!=' ')cout<<s[i][j];
        }
        if(i<5)cout<<endl;
    }
    return 0;
}