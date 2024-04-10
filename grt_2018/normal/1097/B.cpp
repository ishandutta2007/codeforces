#include <iostream>

using namespace std;

#define REP(x,n) for(int x=0; x<(n);x++)
#define FOR(x,b,e) for(int x=b; x<=(e);x++)

int n;
int a[16];

int main()
{
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,(1<<n))
    {
        int s=0;
        FOR(j,0,n-1)
        {
            if((1<<j)&i)
            {
                s+=a[j];
            }
            else
                s-=a[j];
        }
        if(s%360==0)
        {
            cout<<"YES"; return 0;
        }
    }
    cout<<"NO";
    return 0;
}