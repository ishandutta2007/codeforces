#include <iostream>
using namespace std;

char s1[100001],s2[100001];
int s1L=0,s2L=0;

bool CheckStringDivisor(char str[],int L,int div)
{
    int i,k=1;
    for (i=1;i<=L;i++)
    {
        if (str[i]!=str[k])
        return false;
        
        k++;
        if (k>div)
        k-=div;
    }
    return true;
}

int main()
{
    string a,b;
    string d;
    int i;
    int divisor,ctr=0;
    cin>>a;
    cin>>b;
    if (b.length()<a.length())
    {
        d=a;
        a=b;
        b=d;
    }
    for (i=0;i<a.length();i++)
    {
        s1[i+1]=a[i];
    }
    s1L=a.length();
    for (i=0;i<b.length();i++)
    {
        s2[i+1]=b[i];
    }
    s2L=b.length();
    
    for (i=1;i<=s1L;i++)
    {
        if (s1[i]!=s2[i])
        {
            cout<<0<<endl;
            return 0;
        }
    }
    
    for (i=1;i<=s1L;i++)
    {
        if (s1L%i==0)
        {
            if ( CheckStringDivisor(s1,s1L,i) )
            {
                divisor=i;
                break;
            }
        }
    }
    if ( !CheckStringDivisor(s2,s2L,i) )
    {
        cout<<0<<endl;
        return 0;
    }
    for (i=divisor;i<=s1L;i++)
    {
        if (s1L%i==0 && i%divisor==0 && s2L%i==0)
        {
            ctr++;
        }
    }
    cout<<ctr<<endl;
    return 0;
}