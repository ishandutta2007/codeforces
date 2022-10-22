#include <iostream>

using namespace std;

#define MAXN 100000

int n;
int a[MAXN],b[MAXN];
int curr=0;

int main()
{
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=n-1; i>=0;i--)
    {
        if(curr>min(a[i],b[i]))
        {
            if(curr>max(a[i],b[i]))
                {cout<<"NO"; return 0;}
            curr=max(a[i],b[i]);
        }
        else
            curr=min(a[i],b[i]);
        //cout<<curr<<endl;
    }
    cout<<"YES";
    return 0;
}