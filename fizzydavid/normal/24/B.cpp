/*
    Author  : JZdavid
    From    : CF
    Problem : 24B F1 champions
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
const int point[]={25,18,15,12,10,8,6,4,2,1};
int n,m,cnt;
struct person
{
    string name;
    int pnt,cnt[55];
    person()
    {
        name="";
        pnt=0;
        memset(cnt,0,sizeof(cnt));
    }
}p[55];
bool cmp1(person x,person y)
{
    if(x.pnt>y.pnt)return 1;
    else if(x.pnt==y.pnt)
    {
        for(int i=0;i<50;i++)
        {
            if(x.cnt[i]>y.cnt[i])return 1;
            else if(x.cnt[i]<y.cnt[i])return 0;
        }
    }
    return 0;
}
bool cmp2(person x,person y)
{
    if(x.cnt[0]>y.cnt[0])return 1;
    else if(x.cnt[0]==y.cnt[0])
    {
        if(x.pnt>y.pnt)return 1;
        else if(x.pnt==y.pnt)
        {
            for(int i=1;i<50;i++)
            {
                if(x.cnt[i]>y.cnt[i])return 1;
                else if(x.cnt[i]<y.cnt[i])return 0;
            }
        }
    }
    return 0;
}
set<string>name;
map<string,int>ind;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        cin>>m;
        for(int i=0;i<m;i++)
        {
            string s;
            cin>>s;
            int t=name.size();
            name.insert(s);
            if(name.size()==t+1)ind[s]=cnt++;
            p[ind[s]].name=s;
            if(i<10)p[ind[s]].pnt+=point[i];
            p[ind[s]].cnt[i]++;
        }
    }
    /*
    for(int i=0;i<cnt;i++)
    {
        cout<<"name:"<<p[i].name<<endl;
        cout<<"point:"<<p[i].pnt<<endl;
        cout<<"cnt[]:";
        for(int j=0;j<10;j++)cout<<p[i].cnt[j]<<" ";
        cout<<endl;
    }
    */
    sort(p,p+cnt,cmp1);
    cout<<p[0].name<<endl;
    sort(p,p+cnt,cmp2);
    cout<<p[0].name<<endl;
//  system("pause");
    return 0;
}