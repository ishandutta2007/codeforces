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
#define end return 0
struct bracket
{
    int id,dif;
    bool operator<(const bracket &tmpb)const{
        return dif>tmpb.dif;
    }
};
priority_queue<bracket>q;
string s;
int n;
int main()
{
    cin>>s;n=s.size();
    long long cnt=0,res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')cnt++;
        else if(s[i]==')')cnt--;
        else if(s[i]=='?')
        {
            int a,b;scanf("%d%d",&a,&b);
            res+=b;
            cnt--;s[i]=')';
            bracket tmp;
            tmp.id=i,tmp.dif=a-b;
            q.push(tmp);
        }
        while(cnt<0)
        {
            if(q.size()>0)
            {
                int id=q.top().id,val=q.top().dif;
                q.pop();
                s[id]='(';
                res+=val;
            }
            else break;
            cnt+=2;
        }
        if(cnt<0){puts("-1");end;}
    }
    if(cnt!=0){puts("-1");end;}
    cout<<res<<endl<<s;
    end;
}