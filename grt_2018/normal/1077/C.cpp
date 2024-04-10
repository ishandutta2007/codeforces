#include <iostream>
#include <cstdio>

using namespace std;

int n;
int m1,m2;
long long s;
int T[2*100000+1];
int S[2*100000+1],r=0;

int main()
{
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>T[i];
        s+=T[i];
        if(T[i]>=m1)
        {
            m2=m1;
            m1=T[i];
        }
        else if(T[i]>=m2)
        {
            m2=T[i];
        }
    }
    for(int i=0; i<n;i++)
    {
        long long x = s - T[i];
        if(T[i]==m1)
        {
            if((long long)m2*2==x)
            {
                S[r]=i;
                r++;
            }
        }
        else
        {
            if((long long)m1*2==x)
            {
                S[r]=i;
                r++;
            }
        }
    }
    cout<<r<<"\n";
    for(int i=0; i<r;i++)
    {
        cout<<S[i]+1<<" ";
    }
    return 0;
}