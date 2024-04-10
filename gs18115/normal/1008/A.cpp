#include<iostream>
using namespace std;
char s[9999];
char a,b;
int i;
bool chk[9999];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    chk['a']=true;
    chk['e']=true;
    chk['n']=true;
    chk['o']=true;
    chk['i']=true;
    chk['u']=true;
    cin>>s;
    b=s[0];
    for(i=1;s[i];i++)
    {
        a=b;
        b=s[i];
        if(!chk[a]&&!chk[b])
        {
            cout<<"NO";
            return 0;
        }
        if(!chk[a]&&b=='n')
        {
            cout<<"NO";
            return 0;
        }
    }
    if(!chk[b])
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}