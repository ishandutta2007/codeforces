#include <iostream>
#include <stdio.h>
using namespace std;
char a[400051];
int n;
char files[400051][20];
int fil[400051],fails=0;
char work[400051];
int wL=0;
int main()
{
    int i,j;
    char ch;
    i=0;
    while (!cin.eof())
    {
        cin>>ch;
        if (cin.eof())
        break;
        
        i++;
        a[i]=ch;
    }
    n=i;
    
    for (i=0;i<=400050;i++)
    fil[i]=0;
    
    i=1;
    fails=1;
    while (i<=n)
    {
        fil[1]++;
        files[1][ fil[1] ]=a[i];
        if (a[i]=='.')
        break;
        
        i++;
    }
    if (i>n || i==1 || i-1>8)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    i++;
    for (i;i<=n;i++)
    {
        if (a[i]!='.')
        {
            wL++;
            work[wL]=a[i];
        }
        else
        {
            if (wL>11)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            if (wL>3)
            {
                for (j=1;j<=3;j++)
                {
                    fil[fails]++;
                    files[ fails ][ fil[ fails ] ]=work[j];
                }
                fails++;
                for (j=4;j<=wL;j++)
                {
                    fil[fails]++;
                    files[ fails ][ fil[ fails ] ]=work[j];
                }
                fil[fails]++;
                files[ fails ][ fil[fails] ]='.';
                wL=0;
            }
            else
            {
                if (wL<=1)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                fil[fails]++;
                files[ fails ][ fil[ fails ] ]=work[1];
                
                fails++;
                for (j=2;j<=wL;j++)
                {
                    fil[fails]++;
                    files[ fails ][ fil[ fails ] ]=work[j];
                }
                fil[fails]++;
                files[ fails ][ fil[fails] ]='.';
                wL=0;
            }
        }
    }
    if (wL>3 || wL==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        for (j=1;j<=wL;j++)
        {
            fil[fails]++;
            files[ fails ][ fil[ fails ] ]=work[j];
        }
    }
    cout<<"YES"<<endl;
    for (i=1;i<=fails;i++)
    {
        for (j=1;j<=fil[i];j++)
        {
            printf("%c",files[i][j]);
        }
        printf("\n");
    }
    return 0;
}