#include<iostream>
using namespace std;
int main()
{
    int i,n;
    bool b=0;
    string s[3000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(i=0;i<n;i++)
    {
        if(s[i][0]=='O'&&s[i][1]=='O')
        {
            b=1;
            s[i][0]='+';
            s[i][1]='+';
            break;
        }
        if(s[i][3]=='O'&&s[i][4]=='O')
        {
            b=1;
            s[i][3]='+';
            s[i][4]='+';
            break;
        }
    }
    if(b==1)
    {
        cout<<"YES\n";
        for(i=0;i<n;i++)
        {
            cout<<s[i]<<endl;
        }
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}