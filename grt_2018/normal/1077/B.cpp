#include <iostream>
#include <cstdio>

using namespace std;

int n;
bool T[101];
int ile=0;

int main()
{
    cin>>n;
    for(int i=0; i<n;i++) cin>>T[i];
    for(int i=2; i<n;i++)
    {
        if(T[i-2]==T[i]&&T[i]==1&&T[i-1]==0)
        {
            ile++;
            T[i]=0;
        }
    }
    cout<<ile;
    return 0;
}