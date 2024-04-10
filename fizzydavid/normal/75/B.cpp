/*
    Author  : JZdavid
    From    : CF
    Problem : 75B
    Time    : 2014/8/6
    Verdict : Accepting
*/
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
const int INF=1<<28;
const long long LINF=1ll<<61;
set<string> name; 
string num,s;
map<string,int> m;
bool cmp(pair<int,string> a,pair<int,string> b)
{
    if(a.ff<b.ff)return 1;
    else if(a.ff==b.ff)
    {
        return a.ss>b.ss;
    }
    return 0;
}
struct priority
{
    int v;
    string nm;
};
bool operator<(priority a,priority b)
{
    if(a.v<b.v)return 1;
    else if(a.v==b.v)
    {
        return a.nm>b.nm;
    }
    return 0;
}
priority_queue<priority>pq;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string n1,n2;
        cin>>n1;
        cin.ignore();
        char c;
        cin>>c;
        int p=0;
        if(c=='p')
        {
            for(int j=0;j<9;j++)cin.ignore();
            p=15;
        }
        else if(c=='c')
        {
            for(int j=0;j<12;j++)cin.ignore();
            p=10;
        }
        else
        {
            for(int j=0;j<5;j++)cin.ignore();
            p=5;
        }
        string tmp;
        cin>>tmp;
        n2=tmp.substr(0,tmp.size()-2);
        for(int j=0;j<5;j++)cin.ignore();
        if(n1!=s)name.insert(n1);
        if(n2!=s)name.insert(n2);
        if(n1==s)m[n2]+=p;
        if(n2==s)m[n1]+=p;
    }
    for(set<string>::iterator it=name.begin();it!=name.end();it++)
    {
        priority tmp;
        tmp.v=m[*it];
        tmp.nm=*it;
        pq.push(tmp);
    }
    while(!pq.empty())
    {
        cout<<pq.top().nm<<endl;
        pq.pop();
    }
 // system("pause");
    return 0;
}