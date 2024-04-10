#include <iostream>
using namespace std;
int main()
{
    int differences=0,diffs[5];
    int i;
    bool seen[30];
    string a,b;
    cin>>a>>b;
    if (a.length()!=b.length())
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for (i=0;i<a.length();i++)
    {
        if (a[i]!=b[i])
        {
            differences++;
            diffs[differences]=i;
            if (differences>2)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if (differences==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if (differences==2)
    {
        if ( a[ diffs[1] ]==b[ diffs[2] ] && a[ diffs[2] ]==b[ diffs[1] ] )
        {
            cout<<"YES"<<endl;
            return 0;
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if (differences==0)
    {
        for (i=0;i<=29;i++)
        seen[i]=false;
        
        for (i=0;i<a.length();i++)
        {
            if ( seen[ (int)a[i]-(int)'a' ] )
            {
                cout<<"YES"<<endl;
                return 0;
            }
            else
            {
                seen[ (int)a[i]-(int)'a' ]=true;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}