#include <iostream>
using namespace std;
long long a[250001];
int main()
{
    long long n;
    long long i,j;
    long long currX,currind;
    long long maxX,maxind;
    long long step,total=0;
    long long copy;
    long long start=10000,end;
    
    cin>>n;
    
    for (i=10001;i<=n+10000;i++)
    cin>>a[i];
    
    for (i=1;i<=n;i++)
    {
        end=start+n;
        currind=end;
        step=0;
        while( currind-a[currind]>start+1 )
        {
            maxX=999999999;
            for (j=currind-1;j>=currind-a[currind];j--)
            {
                if (j-a[j]<maxX)
                {
                    maxX=j-a[j];
                    maxind=j;
                }
            }
            currind=maxind;
            step++;
        }
        step++;
        total=total+step;
        a[start]=a[end];
        start--;
    }
    cout<<total<<endl;
    return 0;
}