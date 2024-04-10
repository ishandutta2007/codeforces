#include<iostream>
#include<string.h>
#include<map>
using namespace std;
map<string,int>m;
string s[123],S;
int chk[123],n,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    m["purple"]=1;
    m["green"]=2;
    m["blue"]=3;
    m["orange"]=4;
    m["red"]=5;
    m["yellow"]=6;
    s[1]="Power";
    s[2]="Time";
    s[3]="Space";
    s[4]="Soul";
    s[5]="Reality";
    s[6]="Mind";
    cin>>n;
    cout<<(6-n)<<"\n";
    for(i=0;i<n;i++)
    {
        cin>>S;
        chk[m[S]]=1;
    }
    for(i=1;i<=6;i++)
    {
        if(!chk[i])
        {
            cout<<s[i]<<"\n";
        }
    }
    return 0;
}