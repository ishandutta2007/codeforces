#include <iostream>
#include <algorithm>
using namespace std;
struct tile
{
    int daybreak,orgind;
};
tile tiles[1003];
bool alivetiles[1003];

bool SortEm(tile a,tile b)
{
    return (a.daybreak<b.daybreak);
}

int main()
{
    int n;
    int i,ind;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>tiles[i].daybreak;
        tiles[i].orgind=i;
    }
    for (i=0;i<=1002;i++)
    alivetiles[i]=true;
    
    sort(tiles+1,tiles+1+n,SortEm);
    for (i=1;i<=n;i++)
    {
        ind=tiles[i].orgind;
        alivetiles[ind]=false;
        if (alivetiles[ind-1]==false || alivetiles[ind+1]==false || ind==1 || ind==n)
        {
            cout<<tiles[i].daybreak<<endl;
            return 0;
        }
    }
    return 0;
}