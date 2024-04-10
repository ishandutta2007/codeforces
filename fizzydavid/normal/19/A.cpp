/*
    Author  : JZdavid
    From    : CF
    Problem : 19A World Football Cup
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
struct data
{
    string name;
    int goal,miss,pnt;
    data()
    {
        name="";
        goal=miss=pnt=0;
    }
}d[55];
int n;
string name[55];
map<string,int> ind;
bool cmp(data x,data y)
{
    if(x.pnt>y.pnt)return 1;
    else if(x.pnt==y.pnt)
    {
        if(x.goal-x.miss>y.goal-y.miss)return 1;
        else if(x.goal-x.miss==y.goal-y.miss)
        {
            if(x.goal>y.goal)return 1;
        }
    }
    return 0;
}
bool cmp2(data x,data y)
{
    return x.name<y.name;
}
int stoi(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)ans=ans*10+s[i]-'0';
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
        d[i].name=name[i];
        ind[name[i]]=i;
    }
    for(int i=0;i<n*(n-1)/2;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        string s1=t1.substr(0,t1.find('-')),s2=t1.substr(t1.find('-')+1);
        int n1=stoi(t2.substr(0,t2.find(':'))),n2=stoi(t2.substr(t2.find(':')+1));
        if(n1==n2)d[ind[s1]].pnt+=1,d[ind[s2]].pnt+=1;
        else d[ind[s1]].pnt+=(n1>n2)?3:0,d[ind[s2]].pnt+=(n1<n2)?3:0;
        d[ind[s1]].goal+=n1;
        d[ind[s2]].goal+=n2;
        d[ind[s1]].miss+=n2;
        d[ind[s2]].miss+=n1;
    }
    /*
    for(int i=0;i<n;i++)
    {
        cout<<"name:"<<d[i].name<<endl;
        cout<<"informations: goal:"<<d[i].goal<<" miss:"<<d[i].miss<<" pnt:"<<d[i].pnt<<endl;
    }
    */
    sort(d,d+n,cmp);
    sort(d,d+n/2,cmp2);
    for(int i=0;i<n/2;i++)cout<<d[i].name<<endl;
//  system("pause");
    return 0;
}