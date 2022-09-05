#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
using namespace std;
#define iswin(q1,q2) if(q1=='R'&&q2=='S'||q1=='S'&&q2=='P'||q1='P'&&q2=='R')
string s1,s2;
long long gbs(long long a1,long long a2)
{
    long long t,p;
    p=a1*a2;
    if(a1<a2)swap(a1,a2);
    while(a2!=0)
    {
        t=a1%a2;
        a1=a2;
        a2=t;
    }
    return p/a1;
}

int main()
{
    long long n,c1=0,c2=0,i,ans1=0,ans2=0;
    char q1,q2;
    cin>>n>>s1>>s2;
    for(i=1;i<=gbs(s1.size(),s2.size());i++)
    {
        q1=s1[(i-1)%s1.size()];q2=s2[(i-1)%s2.size()];
        if(q1=='R'&&q2=='S'||q1=='S'&&q2=='P'||q1=='P'&&q2=='R')c1++;
        else if(q2=='R'&&q1=='S'||q2=='S'&&q1=='P'||q2=='P'&&q1=='R')c2++;
    }
    for(i=1;i<=n%gbs(s1.size(),s2.size());i++)
    {
        q1=s1[(i-1)%s1.size()];q2=s2[(i-1)%s2.size()];
        if(q1=='R'&&q2=='S'||q1=='S'&&q2=='P'||q1=='P'&&q2=='R')ans1++;
        else if(q2=='R'&&q1=='S'||q2=='S'&&q1=='P'||q2=='P'&&q1=='R')ans2++;
    }
    cout<<c2*(n/gbs(s1.size(),s2.size()))+ans2<<" "<<c1*(n/gbs(s1.size(),s2.size()))+ans1;
    return 0;
}