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
const int INF=1<<28;
const long long LINF=1ll<<61;
const int day[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
ll t[100111];
struct data
{
    string YY,MM,DD,hh,mm,ss;
}time2[100111];
int n,m,size;
string s;
int mystoi(string s)
{
    return (s[0]-'0')*10+s[1]-'0';
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;cin.ignore();
    while(getline(cin,s))
    {
        if(s=="")break;
        t[++size]=(day[mystoi(s.substr(5,2))]+mystoi(s.substr(8,2))-1)*24*60*60
              +mystoi(s.substr(11,2))*60*60+mystoi(s.substr(14,2))*60+mystoi(s.substr(17,2));
        time2[size].YY="2012";
        time2[size].MM=s.substr(5,2);
        time2[size].DD=s.substr(8,2);
        time2[size].hh=s.substr(11,2);
        time2[size].mm=s.substr(14,2);
        time2[size].ss=s.substr(17,2);
    }
    queue<pair<ll,int> >q;
    for(int i=1;i<=size;i++)
    {
        q.push(make_pair(t[i],i));
        if(t[i]-q.front().ff+1>n)q.pop();
        if(q.size()>=m)
        {
            cout<<time2[i].YY<<"-"<<time2[i].MM<<"-"<<time2[i].DD<<" "<<
                  time2[i].hh<<":"<<time2[i].mm<<":"<<time2[i].ss<<endl;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}