#include <iostream>

using namespace std;

int n;
int t[2*100000+1];
int wyn=1;

int main()
{
    cin>>n;
    for(int i=0; i<n;i++)
        cin>>t[i];
    int akt=1;
    for(int i=1; i<n;i++)
    {
        if(t[i-1]*2>=t[i])
            akt++;
        else
            akt=1;
        wyn=max(wyn,akt);
    }
    cout<<wyn;
    return 0;
}